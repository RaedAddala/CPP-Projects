- A process runs within its own virtual address space, distinct from the virtual addrsses spaces of other processes.  

- The virtual address space comprises of 5 sections: 
    - **Text section**: contains binary instructions to be executed by the CPU
    - **Data section**: contains non-zero initialized data
    - **BSS (Block Started by Symbol)**: contains zero-initialized variables and uninitialized static data.  
    - **Heap**: contains the dynamically allocated data. 
    - **Stack**: contains automatic variables and function's arguments.  

- Data, BSS and heap sections are collectively referred as the "data segment".  

- The end of the data segment is demarcated by a pointer named `brk`

- For linux, we can make system call using `sbrk()` to manipulate program break
    - `sbrk(0)` : the current address of `brk`
    - `sbrk(x)` : increment `brk` by x
    - `sbrk(-x)`: decrement `brk` by x
    - On failure, `sbrk()` returns `(void*) -1`

- `sbrk()` is not really thread safe, but the glibc still implement malloc() using `sbrk()` for not too big memory.  
- `mmap()` is better alternative 


- The heap memory is contiguous, so only memory at the end of the heap can be released 


- `pthread_mutex_t` is a data type in the POSIX threads (pthreads) library used to create a mutex lock.  

- A mutex is a synchronization primitive that ensures that only one thread can access a particular section of code or data at a time. 
