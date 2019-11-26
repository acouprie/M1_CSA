#include <omp.h>
#include <stdio.h>

#define N 2050
#define TMAX 4

int main(){
    float T[N] = {100};
    float tmp[N];
    tmp[0] = T[0]; tmp[N-1] = T[N-1];
    for (int i = 1; i < N; i++)
    {
        T[i] = 0;
    }

    #pragma omp parallel
    {
        for (int t = 0; t < TMAX; t++)
        {
            #pragma omp for
            for (int s = 1; s < N-1; s++)
            {
                tmp[s] = T[s];
            }
            // implicit synchronization barrier
            #pragma omp for
            for (int s = 0; s < N-1; s++)
            {
                T[s] = (tmp[s-1] + 4*tmp[s] + tmp[s+1]) / 6;
                printf("%d\n", T[s]);
            }
            // implicit synchronization barrier
        }
    }
    return(0);
}