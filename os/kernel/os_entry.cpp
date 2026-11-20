#include "base.h"
#include "kernel/slab_alloc.h"
#include "kernel/cron.h"

using namespace micronix::kernel;

extern "C" {

void kernel_entry() {
    slab_initialize();
    timer_initialize();
    app_main();
}

}
