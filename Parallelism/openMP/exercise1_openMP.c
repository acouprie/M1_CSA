#include <omp.h>
#include <stdio.h>

#define N 2

int main(){
    int A[N][N], B[N][N], C[N][N];
    #pragma omp parallel num_threads(4)
    {
        for (int i = 0; i < N; i++)
        {
            #pragma omp for
            for (int j = 0; j < N; j++)
            {
                C[i][j] = 0;
                for (int k = 0; k < N; k++)
                {
                    C[i][j] += A[i][k] + B[k][j];
                }
            }
        }
    }
    return(0);
}