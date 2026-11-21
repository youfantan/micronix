#include "timer.h"

extern "C" void TIMER_IRQ_0_Handler() {
    micronix::devices::rp2040::timer0::alarm_intr<0>();
}

extern "C" void TIMER_IRQ_1_Handler() {
    micronix::devices::rp2040::timer0::alarm_intr<1>();
}

extern "C" void TIMER_IRQ_2_Handler() {
    micronix::devices::rp2040::timer0::alarm_intr<2>();
}

extern "C" void TIMER_IRQ_3_Handler() {
    micronix::devices::rp2040::timer0::alarm_intr<3>();
}