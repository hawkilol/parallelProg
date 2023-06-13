%env OMP_NUM_THREADS=4
!nvcc --version
!gcc -o hello -fopenmp code.


#Useful
#gcc –g –fopenmp -o progT progT.c
#./progT

#gcc –g –fopenmp -o progT progT.c
#OMP_NUM_THREADS=6 ./progT

#omp_set_num_threads (4);

#gcc –o primos prog_omp_Numeros_Primos.c –fopenmp –O3 –std=c11 –lm
#./primos 5000000
####
# "-O3" is an optimization flag that instructs the compiler to perform aggressive code optimization at the highest level. This optimization level can improve the execution speed of the resulting program but may also increase the compilation time.
# "-std=c11" specifies the C programming language standard to be used during compilation. In this case, it indicates the C11 standard, which is the 2011 version of the C language standard.
# "-lm" is a linker flag that instructs the compiler to link the math library ("-l" indicates linking and "m" refers to the math library). This library provides mathematical functions like sqrt(), sin(), cos(), etc., that you can use in your C program.
####

#export OMP_NUM_THREADS = 16
