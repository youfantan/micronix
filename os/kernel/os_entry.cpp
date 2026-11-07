#include <base.h>
#include <conf.h>
#include <peripherals/clock.h>

#include <kernel/slab_alloc.h>
using namespace micronix::kernel;


extern "C" {

void clock_init() {
    device_clock_initialize<clk_cfg>();
}

void kernel_entry() {
    slab_initialize();
}

}
