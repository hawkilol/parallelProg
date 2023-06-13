#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>
//Aluno: Kalil Saldanha Kaliffe // 202004940030
int main () {

	int arr1[10], arr2[10], arrSum[10], arrSum1[10], arrSub[10];
	int nthreads, tid, tidSec1, tidSec2;
	nthreads = omp_get_num_threads();
	for(int i = 0; i < 10; i++){
		arr1[i] = i + rand() % 24;
		arr2[i] = i + rand() % 24;
	}

	#pragma omp parallel
	{
		tid = omp_get_thread_num();
		#pragma omp for
		for(int i = 0; i < 10; i++){

			arrSum[i] = arr1[i] + arr2[i];
			printf("\nArr soma Id Thread: %d / %d - Iteracao: %d - valor calc: %d \n", tid, nthreads, i, arrSum[i]);

		}
	}
	#pragma omp parallel sections
	{

		#pragma omp section
		{
	    tidSec1 = omp_get_thread_num();
		for(int i = 0; i < 10; i++){

			arrSum1[i] = arr1[i] + arr2[i];
			printf("\nArr soma - Id Thread: %d / %d - Iteracao: %d - valor calc: %d \n", tid, nthreads, i, arrSum1[i]);

		}
		}

		#pragma omp section
		{
	    tidSec2 = omp_get_thread_num();
		for(int i = 0; i < 10; i++){

			arrSub[i] = arr1[i] - arr2[i];
			printf("\nArr Subtracao - Id Thread: %d / %d - Iteracao: %d - valor calc: %d \n", tid, nthreads, i, arrSub[i]);

		}
		}

	}

	printf("\n Fim do programa \n");


	return 0;

}