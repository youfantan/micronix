#pragma once

namespace micronix::kernel
{
    /*
 * Create process by a function pointer and process profile.
 * Sched will create a process context associated with the function pointer. process will be scheduled in many time slices until sched_destroy_process() is called.
 */
    handle sched_create_process();

    /*
     * Destroy process by handle.
     * A process should call this function at the end of the control flow. Sched will recycle all resources associated with this process.
     */
    void sched_destroy_process(handle proc_handle);

    /*
     * Disable processes schedule and switch.
     * Used in precision sequences control flow like software-implemented high speed bus.
     * When called, sched stop working, util sched_recovery_switching() is called; meanwhile SysTick context is also paused and stored, precision timer could only be used in this status.
     */
    void sched_block_switching();

    /*
     * Recovery process schedule and switch.
     * When called, sched continue working; SysTick will be reconfigured using stored context.
     */
    void sched_recovery_switching();
}