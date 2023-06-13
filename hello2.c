#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    printf("Max Available Procs = %d\n", omp_get_num_procs());
    printf("Max Available Threads = %d\n", omp_get_max_threads());
    int nthreads, tid;

    #pragma omp parallel private(nthreads, tid)
    {
        tid = omp_get_thread_num();
        nthreads = omp_get_num_threads();
        printf("Hello World Thread %d / %d\n", tid, nthreads);


    }

    return 0;
}