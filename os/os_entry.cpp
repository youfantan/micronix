#include <device_spec.h>
#include <base.h>
#include <utils.h>

extern int main();

system_profile sys_prof;

constexpr clock_profile clk_prof = {
    .use_crystal_osc = true,
    .pllp_div = 0x00,
    .pllq_div = 0x00,
    .pllr_div = 0x01,
};

constexpr slab_profile slab_prof[3] = {
    {
        .block_size = 32,
        .slots = 64
    },
    {
        .block_size = 64,
        .slots = 16
    },
    {
        .block_size = 256,
        .slots = 4
    }
};

extern "C" {

void system_init() {
    // Enable HSI
    RCC::CR::HSION = 0x01;
    while (RCC::CR::HSIRDY == false) {}
    RCC::CR::HSIDIV = 0x00;
    // Switch System Clock to HSI
    RCC::CFGR::SW = 0x00;
    // Stop PLL(openocd may start PLL to boost flash)
    RCC::CR::PLLON = false;
    while (RCC::CR::PLLRDY != false) {}
    // Set PLL Vco to 128MHz
    if (clk_prof.use_crystal_osc) {
        // Enable HSE, HSE must be 8MHz
        RCC::CR::HSEON = 0x01;
        while (RCC::CR::HSERDY == 0x00) {}
        RCC::PLLSYSCFGR::PLLSRC = 0x03;
        RCC::PLLSYSCFGR::PLLN = 0x10;
    } else {
        RCC::PLLSYSCFGR::PLLSRC = 0x02;
        RCC::PLLSYSCFGR::PLLN = 0x08;
    }
    RCC::PLLSYSCFGR::PLLM = 0x00;
    constexpr u32 fvco = 128000000;
    RCC::PLLSYSCFGR::PLLR = clk_prof.pllr_div;
    sys_prof.fsysclk = fvco / clk_prof.pllr_div;
    RCC::PLLSYSCFGR::PLLREN = true;
    if constexpr (clk_prof.pllq_div == 0) {
        RCC::PLLSYSCFGR::PLLQEN = false;
        sys_prof.fqclk = 0;
    } else {
        RCC::PLLSYSCFGR::PLLQ = clk_prof.pllq_div;
        sys_prof.fqclk = fvco / clk_prof.pllq_div;
        RCC::PLLSYSCFGR::PLLQEN = true;
    }
    if constexpr (clk_prof.pllp_div == 0) {
        RCC::PLLSYSCFGR::PLLPEN = false;
        sys_prof.fpclk = 0;
    } else {
        RCC::PLLSYSCFGR::PLLP = clk_prof.pllp_div;
        sys_prof.fpclk = fvco / clk_prof.pllp_div;
        RCC::PLLSYSCFGR::PLLPEN = true;
    }


    RCC::CR::PLLON = true;
    while (RCC::CR::PLLRDY == false) {}
    RCC::CFGR::SW = 0x02;
    while (RCC::CFGR::SWS != 0x02) {}
    RCC::CFGR::HPRE = 0x00;
    RCC::CFGR::PPRE = 0x00;
}

int kernel_init() {
    main();
    return 0;
}

}