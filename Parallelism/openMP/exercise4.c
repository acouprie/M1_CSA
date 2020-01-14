#include <omp.h>
#include <stdio.h>

#define ARRAY_SIZE 5
#define NUM_THREADS 4

int main(){
    // shared variables
    int v[ARRAY_SIZE] = {0, 4, 6, 9, 2};
    int maxi = v[0];
    int max[NUM_THREADS] = {0};
    #pragma omp parallel num_threads(NUM_THREADS)
    int id = omp_get_thread_num();
    #pragma omp for
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (v[i] > max[id])
        {
            max[id] = v[i];
        }
    }
    // only one thread remains
    for (int i = 0; i < NUM_THREADS; i++)
    {
        if(max[i] > maxi) {
            maxi = max[i];
        }
    }
    
    printf("%i \n", maxi);
    return(maxi);
}