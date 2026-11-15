#include <base.h>
#include <kernel/slab_alloc.h>

using namespace micronix::kernel;

extern "C" {

void kernel_entry() {
    slab_initialize();
    app_main();
}

}
