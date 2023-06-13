#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 20

int main(int argc, char *argv[])
{
    float a[N], b[N], c[N];
    #pragma omp parallel
        #pragma omp single
        printf("Inicio da região paralela número de threads = % d\n", omp_get_thread_num());
        #pragma omp for
        for (int i = 0; i < N; i++)
        {
            c[i] = a[i] + b[i];
            printf("Thread % d executa a iteração % d do loop\n", omp_get_thread_num(), i);
        }

}