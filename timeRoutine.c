#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#define N 10000

int main(int argc, char *argv[])
{
    int i, n;
    float a[N], b[N], c[N];
    double inicio, fim;

    inicio = omp_get_wtime();

    for (i=0; i < N; i++) {
        a[i] = b[i] = i * 1.0;
    }
    n = N;

    #pragma omp parallel num_threads(4)
    {
        int id = omp_get_thread_num();

        if (id == 0) {
            int num_procs = omp_get_num_procs();
            int max_threads = omp_get_max_threads();
            printf("Número de processadores disponíveis = %d\n", num_procs);
            printf("Número Máximo de Threads = %d\n", max_threads);
        }
        #pragma omp for
        for (i=0; i < n; i++) {
            c[i] = a[i] + b[i];
            printf("Thread %d executa a iteração %d do loop com valor %f\n", id, i, c[i]);
        }
    }
    fim = omp_get_wtime();
    printf("Tempo de Execução = %3.4f segundos\n", fim - inicio);
    printf("Precisão do Relógio = %3.9f segundos\n", omp_get_wtick());

}