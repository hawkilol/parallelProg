#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main(int argc, char *argv[])
{
    int secao = 0;

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            int id = omp_get_threads_num();
            secao++;
            printf("Ordem de execução da sessão %d, thread %d\n", secao, id);
        }

        #pragma omp section
        {
            int id = omp_get_thread_num();
            secao++;
            printf("Ordem de execução da sessão %d, thread %d\n", secao, id);
        }
    }
}