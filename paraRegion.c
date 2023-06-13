#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[]){
  omp_set_num_threads(4);
  printf("Número de Threads fora da região paralela = %d\n", omp_get_num_threads());

  #pragma omp parallel
  {
    int nthreads, id;
    id = omp_get_thread_num();
    printf("Eu sou a thread = %d\n", id);

    if(id == 0){
      nthreads = omp_get_num_threads();
      printf("Número de Threads na região paralela = %d\n", nthreads);
    }

  }
  return 0;

}