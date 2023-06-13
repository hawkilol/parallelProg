#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

    #pragma omp parallel num_threads(4)
    {
      int id = omp_get_thread_num();
      int num_threads = omp_get_num_threads();

      if(id == 0){
        printf("Estou atrasada para a barreira ! Tecle enter \\n ");
        getchar();
      }
      #pragma omp barrier
        printf("Cheguei na barreira. Eu sou a %d de %d threads \\n", id, num_threads);
    }
    return 0;
}