#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define SIZE 1000
#define MAX_THREADS 16

int* init_matrix(){
  int* matrix = ( int* ) malloc( SIZE * SIZE * sizeof( int ) );
  for( int i = 0; i < SIZE; i++ ){
    for( int j = 0; j < SIZE; j++ ){
      matrix[ i * SIZE + j ] = i * SIZE + j;
    }
  }
  return matrix;
}


int sum_vector( int* matrix, int n_cores ) {
    int local_sum[MAX_THREADS] = {0};
    int sum = 0;
    /* Computing the sum of the elements of matrix using a shared vector for storing local sums */
    #pragma omp parallel num_threads(n_cores)
    {
        int num_thread = omp_get_thread_num();
        #pragma omp for
        for( int i = 0; i < SIZE; i++ ) {
            for( int j = 0; j < SIZE; j++ ) {
                local_sum[num_thread] += matrix[ i * SIZE + j ];
            }
        }
    }
    for (int i = 0; i < n_cores; i++)
    {
        sum += local_sum[i];
    }
    return sum;
}

int sum_private( int* matrix, int n_cores ){
    int sum = 0;
    /* Computing the sum of the elements of matrix using private variables */
    #pragma omp parallel num_threads(n_cores)
    {
        #pragma omp for reduction(+ : sum)
        for( int i = 0; i < SIZE; i++ ) {
            for( int j = 0; j < SIZE; j++ ){
                sum += matrix[ i * SIZE + j ];
            }
        }
    }
    return sum;
}


int sum_sequential( int* matrix ){
  /* Sequential version */
  int sum = 0;
  for( int i = 0; i < SIZE; i++ ){
    for( int j = 0; j < SIZE; j++ ){
      sum += matrix[ i * SIZE + j ];
    }
  }

  return sum;
}

int main(){
  int* matrix = init_matrix();
  int val;
  int n_cores;
  /* Sequential sum */
  volatile double t_start = omp_get_wtime(), t_end;
  val = sum_sequential( matrix );
  t_end = omp_get_wtime();

  printf( "Sequential sum:\n\tReturn value: %d,\n\tDuration: %lf\n", val, t_end-t_start );

  /* Parallel sum using private variables */
  for(n_cores = 2; n_cores <= MAX_THREADS; n_cores *= 2){
    t_start = omp_get_wtime();
    val = sum_private( matrix, n_cores );
    t_end = omp_get_wtime();

    printf( "Parallel sum on %d cores (private var):\n\tReturn value: %d,\n\tDuration: %lf\n", n_cores, val, t_end-t_start );
  }

  /* Parallel sum using shared vector */
  for(n_cores = 2; n_cores <= MAX_THREADS; n_cores *= 2){
    t_start = omp_get_wtime();
    val = sum_vector( matrix, n_cores );
    t_end = omp_get_wtime();

    printf( "Parallel sum on %d cores (shared vector):\n\tReturn value: %d,\n\tDuration: %lf\n", n_cores, val, t_end-t_start );
  }
}
