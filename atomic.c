#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 5

int main(int argc, char *argv[])
{
    int i, id, n;
    float a[N];
    float sum = 0.0, sumLocal = 0.0;

    for (i=0; i < N; i++) {
        a[i] = i*1.0;
    }
    n = N;

    #pragma omp parallel shared(n,sum) private(id,sumLocal)
    {
        id = omp_get_thread_num();

        #pragma omp of
        for (i=0; i < n; i++) {
            sumLocal += a[i];
        }

        #pragma omp atomic update

            sum += sumLocal;
            printf("Id = %d: sumLocal = %f: sum = %f:\n", id, sumLocal, sum);


    }
    printf("Valor da soma após a região paralela: %f\n", sum);
}