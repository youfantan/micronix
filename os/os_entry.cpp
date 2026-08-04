#include <device_spec.h>
#include <base.h>
#include <utils.h>

extern int main();

constexpr slab_profile slab_profiles[3] = {
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

}

int kernel_init() {
    main();
    return 0;
}

}