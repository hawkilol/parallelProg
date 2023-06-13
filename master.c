#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  int a, i, n=5, b[n];
  #pragma omp parallel shared(a,b) private(i)
  {
    #pragma omp master
    {
      a = 10;
      printf("Construtor master é executado pela thread %d\n", omp_get_thread_num());
    }
    #pragma omp barrier

    #pragma omp for
      for(i = 0; i < n; i++)
        b[i] = a;


  }
      printf("Apos a regiao paralela: \n");
      for(i =0; i < n ; i++)
        printf("b[%d] = %d\n", i, b[i]);
}