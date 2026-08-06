#include <device_spec.h>

static void delay_nop(uint32_t count);

int main() {
    RCC::CFGR::MCOSEL = 0x01;
    RCC::CFGR::MCOPRE = 0x00;
    RCC::IOPENR::GPIOAEN = 0x01;
    GPIOA::AFRH::AFSEL8 = 0x00;
    GPIOA::MODER::MODER8 = 0x02;
    GPIOA::OTYPER::OT8 = 0x00;
    GPIOA::OSPEEDR::OSPEEDR8 = 0x03;
    while (true) {

    }
}