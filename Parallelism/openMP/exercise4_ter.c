#include <omp.h>
#include <stdio.h>

#define ARRAY_SIZE 5
#define NUM_THREADS 4

int main(){
    // shared variables
    int v[ARRAY_SIZE] = {0, 4, 6, 9, 2};
    int maxi = v[0];
    int max[NUM_THREADS] = {0};
    #pragma omp parallel
        #pragma omp for reduction(max : maxi)
        for (int i = 0; i < ARRAY_SIZE; i++) {
            if (maxi < v[i])
            {
                maxi = v[i];
            }
        }
    
    printf("%i \n", maxi);
    return(maxi);
}