#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 10000

int main(int argc, char *argv[])
{
    printf("Max Available Procs = %d\n", omp_get_num_procs());
    printf("Max Available Threads = %d\n", omp_get_max_threads());
    int i, n = 20;
    printf("Cláusula static SEM o parâmetro tam\n");

    #pragma omp parallel for schedule (static) num_threads (4)
    for (i = 0; i < n; ++i) {
        printf("ID = %d iteração = %d\n", omp_get_thread_num(), i);
    }
    printf("Cláusula static COM o parâmetro tam\n");

    #pragma omp parallel for schedule (static,3) num_threads (4)
        for (i = 0; i < n; i++) {
            printf("ID = %d iteração = %d\n", omp_get_thread_num(),i);
        }
    return 0;
}
