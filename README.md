# OS Scheduler

This project extends the functionality of the OS Scheduler to include advanced CPU scheduling algorithms and dynamic memory allocation, providing a comprehensive simulation of an operating system. The implementation showcases strong proficiency in C programming, emphasizing intricate algorithmic design and effective data structure utilization for both CPU and memory management.

## Implemented Algorithms

### Scheduling Algorithms
1. Non-preemptive Highest Priority First (HPF)
2. Shortest Remaining Time Next (SRTN)
3. Round Robin (RR)

### Memory Allocation Algorithms
1. First Fit
2. Buddy Memory Allocation

These algorithms collectively ensure effective utilization of the total memory space, dynamically allocating and deallocating memory for arriving and departing processes.

## Simulation Components:

1. **Process Generator:** Simulates process creation, reads input files, and initiates scheduler and clock processes.
2. **Clock Module:** Emulates an integer time clock.
3. **Scheduler:** Core component managing processes, states, and execution based on scheduling algorithms.
4. **Process:** Represents CPU-bound processes and notifies the scheduler upon termination.

