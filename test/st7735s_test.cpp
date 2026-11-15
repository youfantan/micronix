// Standalone test (run from the repository root):
// em++ -std=c++20 -Iinclude test/st7735s_test.cpp -o build/st7735s_test.js
// node build/st7735s_test.js
#include "../modules/st7735s.h"
#include "../modules/st7735s.h" // Verify the include guard.
#include "../include/subsystem/luciferin/graphics2d.h"
#include <cassert>
#include <vector>

namespace {
    struct transfer {
        bool data;
        std::vector<u8> bytes;
    };
    std::vector<transfer> transfers;
    std::vector<u32> delays;
    int exceptions = 0;
    int fail_at = -1;

    template<int Id, bool Null = false>
    struct gpio {
        inline static bool high = false;
        inline static int starts = 0;
        inline static int stops = 0;
        inline static const gpio null {};
        constexpr static bool is_null = Null;
        static void init(const micronix::peripherals::gpio_init_cfg&) {
            assert(!Null);
            ++starts;
        }
        static void set() { assert(!Null); high = true; }
        static void reset() { assert(!Null); high = false; }
        static void output(bool value) { high = value; }
        static bool input() { return high; }
        static void destory() { assert(!Null); ++stops; }
    };
    using cs = gpio<0>;
    using dc = gpio<1>;
    using blk = gpio<2>;
    using rst = gpio<3>;
    using null_gpio = gpio<4, true>;

    struct spi {
        static void init(const micronix::peripherals::spi_config&) {}
        static bool write_byte(u8) { return true; }
        static u8 read_byte() { return 0; }
        static bool batch_write(const micronix::utf8_string&) { return true; }
        static micronix::utf8_string batch_read();
        static void batch_read(u8*, u32) {}
        static bool batch_write(const u8* data, u32 len) {
            assert(!cs::high);
            assert(data && len);
            transfers.push_back({dc::high, {data, data + len}});
            return static_cast<int>(transfers.size()) != fail_at;
        }
        static void destroy() { assert(false); } // Bus belongs to the caller.
    };

    using display = micronix::modules::st7735s<spi, cs, blk, rst, dc, {128, 160, 2, 1}>;
    using adapter = display::adapter;
    using optional = micronix::modules::st7735s<spi, cs, null_gpio, null_gpio, dc,
        {160, 128, 1, 2, 0x28, true}>;
    struct custom_cmds : micronix::modules::st7735s_init_cmds {
        constexpr static u8 frame_rate[] {0x02, 0x35, 0x36};
    };
    using custom = micronix::modules::st7735s<spi, cs, null_gpio, null_gpio, dc,
        {128, 128}, custom_cmds>;
    using graphics = micronix::luciferin::graphics2d<adapter>;
    static_assert(graphics::get_framebuffer_size() == 128 * 160 * 2);

    void expect(unsigned i, bool data, std::initializer_list<u8> bytes) {
        assert(i < transfers.size());
        assert(transfers[i].data == data);
        assert(transfers[i].bytes == std::vector<u8>(bytes));
    }

    void check_init() {
        expect(0, false, {0x01});
        expect(1, false, {0x11});
        expect(2, false, {0xb1});
        expect(3, true, {0x01, 0x2c, 0x2d});
        expect(6, false, {0xb3});
        expect(7, true, {0x01, 0x2c, 0x2d, 0x01, 0x2c, 0x2d});
        expect(26, false, {0x3a});
        expect(27, true, {0x05});
        expect(28, false, {0x36});
        expect(31, false, {0x13});
        expect(32, false, {0x29});
        assert(cs::high);
    }
}

namespace micronix::kernel {
    void timer_sleep(u32 us) { delays.push_back(us); }
    void exception_throw() { ++exceptions; }
}

int main() {
    adapter::initialize();
    check_init();
    assert(blk::high && rst::high);
    assert((delays == std::vector<u32>{1000, 10000, 120000, 120000, 120000, 10000, 100000}));
    adapter::initialize();
    assert(transfers.size() == 33 && cs::starts == 1);

    std::vector<u8> framebuffer(graphics::get_framebuffer_size());
    display::context::color_format::set_pixel(framebuffer.data(), 0, {255, 0, 0});
    transfers.clear();
    {
        graphics renderer(framebuffer.data(), nullptr);
        renderer.present();
        expect(0, false, {0x2a});
        expect(1, true, {0, 2, 0, 129});
        expect(2, false, {0x2b});
        expect(3, true, {0, 1, 0, 160});
        expect(4, false, {0x2c});
        assert(transfers.size() == 6 && transfers[5].data);
        assert(transfers[5].bytes == framebuffer);
        assert(transfers[5].bytes[0] == 0xf8 && transfers[5].bytes[1] == 0);
    }
    expect(6, false, {0x28});
    expect(7, false, {0x10});
    assert(!blk::high && !rst::high && cs::high);
    assert(cs::stops == 1 && dc::stops == 1 && blk::stops == 1 && rst::stops == 1);
    adapter::destroy();
    assert(transfers.size() == 8);

    transfers.clear();
    delays.clear();
    optional::adapter::initialize();
    check_init();
    expect(29, true, {0x28});
    expect(30, false, {0x21});
    assert((delays == std::vector<u32>{120000, 120000, 10000, 100000}));
    transfers.clear();
    optional::adapter::present(framebuffer.data());
    expect(1, true, {0, 1, 0, 160});
    expect(3, true, {0, 2, 0, 129});
    optional::adapter::destroy();
    assert(null_gpio::starts == 0 && null_gpio::stops == 0);

    transfers.clear();
    custom::adapter::initialize();
    expect(3, true, {0x02, 0x35, 0x36});
    custom::adapter::destroy();

    // Every failed initialization transfer must stop, deselect and permit retry.
    for (int failure = 1; failure <= 33; ++failure) {
        transfers.clear();
        fail_at = failure;
        const int before = exceptions;
        adapter::initialize();
        assert(exceptions == before + 1 && cs::high && !blk::high);
        fail_at = -1;
        transfers.clear();
        adapter::initialize();
        check_init();
        adapter::destroy();
    }
    // Also check each phase of a framebuffer transfer, including its payload.
    for (int failure = 1; failure <= 6; ++failure) {
        adapter::initialize();
        transfers.clear();
        fail_at = failure;
        const int before = exceptions;
        adapter::present(framebuffer.data());
        assert(exceptions == before + 1 && cs::high && !blk::high);
        fail_at = -1;
    }
    adapter::initialize();
    const int before = exceptions;
    adapter::present(nullptr);
    assert(exceptions == before + 1 && cs::high && !blk::high);
    transfers.clear();
    adapter::present(framebuffer.data());
    assert(exceptions == before + 2 && transfers.empty());
}
