#include <omp.h>
#include <stdio.h>
typedef int bool;
#define TRUE 1
#define FALSE 0
#define LIMITE 100

int main(){
    int num_primes = 0;
    #pragma omp parallel
    #pragma omp for
    for (int i = 0; i < LIMITE; i++) {
        bool is_prime = TRUE;
        for (int j = 2; j < i; j++)
        {
            if (i%j == 0)
            {
                is_prime = FALSE;
                break;
            }
        }
        if (is_prime)
        {
            #pragma omp atomic
            num_primes++;
        }
    }
    
    printf("%i \n", num_primes);
    return(num_primes);
}