#include <omp.h>
#include <stdio.h>
int main(){
    #pragma omp parallel num_threads(4)
    {
        int n = omp_get_thread_num();
        printf("I am thread %d\n",n);
    }
    return(0);
}