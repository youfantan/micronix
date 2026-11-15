#include <device.h>
#include <register_spec.h>
#include <config/kern_conf.h>
#include <utils/algorithms.h>

void clock_init() {
    static_assert(clk_cfg.target_frequency_hz <= 150_mhz);
    static_assert(clk_cfg.osc_frequency_hz * clk_cfg.fb_div / clk_cfg.post_div1 / clk_cfg.post_div2 == clk_cfg.target_frequency_hz);
    static_assert(in_range_cc(clk_cfg.fb_div, 16, 320));
    static_assert(in_range_cc(clk_cfg.post_div1, 1, 7));
    static_assert(in_range_cc(clk_cfg.post_div2, 1, 7));
    static_assert(in_range_cc(clk_cfg.osc_frequency_hz * clk_cfg.fb_div, 750_mhz, 1600_mhz));
    XOSC::CTRL::FREQ_RANGE = 0xaa0; // 1 - 15MHz
    XOSC::CTRL::ENABLE = 0xFAB;
    while (!XOSC::STATUS::STABLE) {} // Wait XOSC stable

    RESETS::RESET::PLL_SYS = 0x00;
    while (!RESETS::RESET_DONE::PLL_SYS) {}

    PLL_SYS::CS::REFDIV = 0x01;
    PLL_SYS::FBDIV_INT::FBDIV_INT_ = clk_cfg.fb_div;
    PLL_SYS::PWR::PD = 0x00; // Start SYS_PLL
    PLL_SYS::PWR::VCOPD = 0x00;
    while (!PLL_SYS::CS::LOCK) {} // Wait SYS_PLL locked
    PLL_SYS::PRIM::POSTDIV1 = clk_cfg.post_div1;
    PLL_SYS::PRIM::POSTDIV2 = clk_cfg.post_div2;
    PLL_SYS::PWR::POSTDIVPD = 0x00;

    auto wait_clock = [](auto& reg, u8 n) {
        while (reg != (1 << n)) {}
    };

    CLOCKS::CLK_REF_CTRL::SRC = 0x02;
    wait_clock(CLOCKS::CLK_REF_SELECTED::CLK_REF_SELECTED_, 0x02); // Wait CLK_REF switched to XOSC
    CLOCKS::CLK_SYS_CTRL::SRC = 0x00;
    CLOCKS::CLK_SYS_RESUS_CTRL::ENABLE = 0x00;
    wait_clock(CLOCKS::CLK_SYS_SELECTED::CLK_SYS_SELECTED_, 0x00); // Wait CLK_SYS switched to CLK_REF
    CLOCKS::CLK_SYS_CTRL::AUXSRC = 0x00;
    CLOCKS::CLK_SYS_DIV::FRAC = 0x00;
    CLOCKS::CLK_SYS_DIV::INT = 0x01;
    CLOCKS::CLK_SYS_CTRL::SRC = 0x01;
    wait_clock(CLOCKS::CLK_SYS_SELECTED::CLK_SYS_SELECTED_, 0x01); // Wait CLK_SYS switched to SYS_PLL
}
