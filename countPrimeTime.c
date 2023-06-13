#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#define SOMA_INICIAL 1000

int primo (long int n) {
    long int i;

    for (i = 3; i < (sqrt(n) + 1); i+=2) {
        if (n%i == 0) {
            return 0;
        }
        printf("Primo! -> %ld\n", n);
        return 1;
    }
}

int main(int argc, char *argv[])
{
   double t_inicio, t_fim;
   long int i, n, total;
    if (argc < 2) {
        printf("Valor inválido! Entre com o valor do maior inteiro\n");
        return 0;
    }
    else {
        n = strtol(argv[1], (char **) NULL, 10);
    }
    total = 0;
    t_inicio = omp_get_wtime();

    #pragma omp parallel for reduction(+:total) schedule(static)
        for (i = 3; i <= n; i += 2) {
            if (primo(i) == 1) {
                total++;
            }
        }
        total += 1;
    t_fim = omp_get_wtime();
    printf("Quantidade de Primos entre 1 e %ld: %ld\n", n, total);
    printf("Tempo de execução: %f com %d threads\n", (t_fim - t_inicio), omp_get_max_threads());

    return 0;
}
