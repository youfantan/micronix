#include <device_spec.h>

uint32_t SystemCoreClock = 16000000UL;

static void SystemClock_Config();
static void delay_nop(uint32_t count);

int main() {
    SystemClock_Config();
    RCC::IOPENR::GPIOAEN = 0x01;
    GPIOA::MODER::MODER6 = 0x01;
    GPIOA::OTYPER::OT6 = 0x00;
    GPIOA::OSPEEDR::OSPEEDR6 = 0x04;
    while (true) {
        GPIOA::BSRR::BS6 = 0x01;
        delay_nop(1000UL);
        GPIOA::BRR::BR6 = 0x01;
        delay_nop(1000UL);
    }
}

static void SystemClock_Config()
{
    RCC::CR::HSION = 0x01;
    while (RCC::CR::HSIRDY == 0x00) {}
    RCC::CR::HSIDIV = 0x00;
    RCC::CFGR::SW = 0x00;
    RCC::CFGR::HPRE = 0x00;
    RCC::CFGR::PPRE = 0x00;
}

static void delay_nop(uint32_t count) {
    while (count--)
    {
        __NOP();
    }
}
