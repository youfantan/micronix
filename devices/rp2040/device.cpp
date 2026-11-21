#include <device.h>
#include <register_spec.h>
#include <config/kern_conf.h>
#include <utils/algorithms.h>

void clock_init() {
    static_assert(clk_cfg.target_frequency_hz <= 150_mhz);
    static_assert(clk_cfg.osc_frequency_hz * clk_cfg.sys_fb_div / clk_cfg.sys_div1 / clk_cfg.sys_div2 == clk_cfg.target_frequency_hz);
    static_assert(clk_cfg.osc_frequency_hz * clk_cfg.usb_fb_div / clk_cfg.usb_div1 / clk_cfg.usb_div2 == 48_mhz);
    static_assert(in_range_cc(clk_cfg.sys_fb_div, 16, 320));
    static_assert(in_range_cc(clk_cfg.sys_div1, 1, 7));
    static_assert(in_range_cc(clk_cfg.sys_div2, 1, 7));
    static_assert(in_range_cc(clk_cfg.usb_fb_div, 16, 320));
    static_assert(in_range_cc(clk_cfg.usb_div1, 1, 7));
    static_assert(in_range_cc(clk_cfg.usb_div2, 1, 7));
    static_assert(in_range_cc(clk_cfg.osc_frequency_hz * clk_cfg.sys_fb_div, 750_mhz, 1600_mhz));
    static_assert(in_range_cc(clk_cfg.osc_frequency_hz * clk_cfg.usb_fb_div, 750_mhz, 1600_mhz));
    XOSC::CTRL::FREQ_RANGE = 0xaa0; // 1 - 15MHz
    XOSC::CTRL::ENABLE = 0xFAB;
    while (!XOSC::STATUS::STABLE) {} // Wait XOSC stable

    RESETS::RESET::PLL_SYS = 0x00;
    while (!RESETS::RESET_DONE::PLL_SYS) {}
    PLL_SYS::CS::REFDIV = 0x01;
    PLL_SYS::FBDIV_INT::FBDIV_INT_ = clk_cfg.sys_fb_div;
    PLL_SYS::PWR::PD = 0x00; // Start PLL_SYS
    PLL_SYS::PWR::VCOPD = 0x00;
    while (!PLL_SYS::CS::LOCK) {} // Wait PLL_SYS locked
    PLL_SYS::PRIM::POSTDIV1 = clk_cfg.sys_div1;
    PLL_SYS::PRIM::POSTDIV2 = clk_cfg.sys_div2;
    PLL_SYS::PWR::POSTDIVPD = 0x00;

    RESETS::RESET::PLL_USB = 0x00;
    while (!RESETS::RESET_DONE::PLL_USB) {}
    PLL_USB::CS::REFDIV = 0x01;
    PLL_USB::FBDIV_INT::FBDIV_INT_ = clk_cfg.usb_fb_div;
    PLL_USB::PWR::PD = 0x00; // Start PLL_USB
    PLL_USB::PWR::VCOPD = 0x00;
    while (!PLL_USB::CS::LOCK) {}
    PLL_USB::PRIM::POSTDIV1 = clk_cfg.usb_div1;
    PLL_USB::PRIM::POSTDIV2 = clk_cfg.usb_div2;
    PLL_USB::PWR::POSTDIVPD = 0x00;


    auto wait_clock = [](auto& reg, u8 n) {
        while (reg != (1 << n)) {}
    };

    CLOCKS::CLK_REF_CTRL::SRC = 0x02;
    wait_clock(CLOCKS::CLK_REF_SELECTED::CLK_REF_SELECTED_, 0x02); // Wait CLK_REF switched to XOSC
    constexpr u32 tick_hz = micronix::devices::rp2040::tick_frequency_hz;
    static_assert(tick_hz > 0 && clk_cfg.osc_frequency_hz % tick_hz == 0);
    constexpr u32 cycles = clk_cfg.osc_frequency_hz / tick_hz;
    static_assert(cycles >= 1 && cycles <= 0x1ff);
    WATCHDOG::TICK::Write((1u << WATCHDOG_TICK_ENABLE.off) | cycles);
    while (!WATCHDOG::TICK::RUNNING) {}
    CLOCKS::CLK_SYS_CTRL::SRC = 0x00;
    CLOCKS::CLK_SYS_RESUS_CTRL::ENABLE = 0x00;
    wait_clock(CLOCKS::CLK_SYS_SELECTED::CLK_SYS_SELECTED_, 0x00); // Wait CLK_SYS switched to CLK_REF
    CLOCKS::CLK_SYS_CTRL::AUXSRC = 0x00;
    CLOCKS::CLK_SYS_DIV::FRAC = 0x00;
    CLOCKS::CLK_SYS_DIV::INT = 0x01;
    CLOCKS::CLK_SYS_CTRL::SRC = 0x01;
    wait_clock(CLOCKS::CLK_SYS_SELECTED::CLK_SYS_SELECTED_, 0x01); // Wait CLK_SYS switched to PLL_SYS
    CLOCKS::CLK_SYS_RESUS_CTRL::ENABLE = 0x01;
    CLOCKS::CLK_PERI_CTRL::AUXSRC = 0x00;
    CLOCKS::CLK_PERI_CTRL::ENABLE = 0x01;
    wait_clock(CLOCKS::CLK_PERI_SELECTED::CLK_PERI_SELECTED_, 0x00); // Wait CLK_PERI switched to CLK_SYS
    CLOCKS::CLK_USB_CTRL::AUXSRC = 0x00;
    CLOCKS::CLK_USB_DIV::INT = 0x01;
    CLOCKS::CLK_USB_CTRL::ENABLE = 0x01;
    wait_clock(CLOCKS::CLK_USB_SELECTED::CLK_USB_SELECTED_, 0x00); // Wait CLK_USB switched to PLL_USB
    CLOCKS::CLK_ADC_CTRL::AUXSRC = 0x00;
    CLOCKS::CLK_ADC_DIV::INT = 0x01;
    CLOCKS::CLK_ADC_CTRL::ENABLE = 0x01;
    wait_clock(CLOCKS::CLK_ADC_SELECTED::CLK_ADC_SELECTED_, 0x00); // Wait CLK_ADC switched to PLL_USB
}
