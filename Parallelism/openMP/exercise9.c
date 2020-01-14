#include <omp.h>
#include <stdio.h>
typedef int bool;
#define TRUE 1
#define FALSE 0
#define LIMITE 100
#define NUM_THREADS 4

int main(){
    int num_primes = 0;
    #pragma omp parallel
    #pragma omp for
    for (int i = 0; i < LIMITE; i++) {

    }
    
    printf("%i \n", num_primes);
    return(num_primes);
}