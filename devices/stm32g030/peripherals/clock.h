#pragma once

#include <base.h>
#include <conf.h>
#include <device.h>
#include <register_spec.h>

template<clock_config CFG>
static void device_clock_initialize() {
    static_assert(CFG.mp_factor > 0);
    static_assert(CFG.mp_factor * CFG.base_freq <= 64000000);
    if constexpr(CFG.mp_factor == 1) {
        // Use oscillator as clock source
        if constexpr (CFG.osc_type == oscillator_type::internal_rc_oscillator) {
            // Enable HSI
            RCC::CR::HSION = true;
            while (RCC::CR::HSIRDY == false) {}
            RCC::CR::HSIDIV = 0x00;
            // Switch system clock to HSI
            RCC::CFGR::SW = 0x00;
            // AHB and APB clock have the same frequency as System Clock
            RCC::CFGR::HPRE = 0x00;
            RCC::CFGR::PPRE = 0x00;
        } else {
            // Enable HSE
            RCC::CR::HSEON = true;
            while (RCC::CR::HSERDY == false) {}
            // Switch system clock to HSE
            RCC::CFGR::SW = 0x01;
            // AHB and APB clock have the same frequency as System Clock
            RCC::CFGR::HPRE = 0x00;
            RCC::CFGR::PPRE = 0x00;
        }
    } else {
        // Switch to HSI first
        RCC::CR::HSION = true;
        while (RCC::CR::HSIRDY == false) {}
        RCC::CR::HSIDIV = 0x00;
        RCC::CFGR::SW = 0x00;
        // Stop PLL(openocd may start PLL to boost flash)
        RCC::CR::PLLON = false;
        // Set PLL Vco to 128MHz
        if constexpr (CFG.osc_type == oscillator_type::external_crystal_oscillator) {
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
        RCC::PLLSYSCFGR::PLLR = 0x10 / CFG.mp_factor - 1;
        RCC::PLLSYSCFGR::PLLREN = true;
        if constexpr (CFG.pll_q == 0) {
            RCC::PLLSYSCFGR::PLLQEN = false;
        } else {
            RCC::PLLSYSCFGR::PLLQ = CFG.pll_q;
            RCC::PLLSYSCFGR::PLLQEN = true;
        }
        if constexpr (CFG.pll_p == 0) {
            RCC::PLLSYSCFGR::PLLPEN = false;
        } else {
            RCC::PLLSYSCFGR::PLLP = CFG.pll_p;
            RCC::PLLSYSCFGR::PLLPEN = true;
        }
        // Set flash wait states for the target SYSCLK before switching to PLL
        if constexpr (CFG.mp_factor * CFG.base_freq <= 24000000) {
            FLASH::ACR::LATENCY = 0x00;
        } else if constexpr (CFG.mp_factor * CFG.base_freq <= 48000000) {
            FLASH::ACR::LATENCY = 0x01;
        } else {
            FLASH::ACR::LATENCY = 0x02;
        }
        FLASH::ACR::PRFTEN = true;
        // Enable PLL
        RCC::CR::PLLON = true;
        while (RCC::CR::PLLRDY == false) {}
        // Select PLLR as System Clock
        RCC::CFGR::SW = 0x02;
        while (RCC::CFGR::SWS != 0x02) {}
        RCC::CFGR::HPRE = 0x00;
        RCC::CFGR::PPRE = 0x00;
    }
}