#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "header.h"

pthread_t threads[MATRIX_COLUMNS];

int main(int argc, char *argv[]) {
    int matrix[MATRIX_SIZE];
    int i;

    createMatrix(&matrix[0]);
    displayMatrix(&matrix[0]);

    for(i = 0; i < MATRIX_COLUMNS; i++) {
        if (pthread_create(&threads[i], NULL, init_thread, &matrix[0])) {
            printf("Can not create a thread\n");
            exit(1);
        }
    }
    for (i = 0; i < MATRIX_COLUMNS; i++) {
        pthread_join(threads[i], NULL);
    }

    computeTotal(&matrix[0]);
    return EXIT_SUCCESS;
}

void *init_thread(int *arg){
    int index = 0;
    pthread_t id = pthread_self();
    for (int i = 0; i < MATRIX_COLUMNS; i++)
    {
        if(pthread_equal(id,threads[i]))
        {
            index = i;
            break;
        }
    }
    
    computeRows(arg, index);
    pthread_exit(NULL);
}

void computeTotal(int *matrix) {
    int total = 0;
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        total += matrix[i];
    }
    printf("The total values in the matrix is %d \n", total);
}

void computeRows(int *matrix, int index) {
    int total = 0;
    int total_row = 0;
    int end_row = (index * MATRIX_ROWS) + MATRIX_ROWS;
    int x = index * MATRIX_ROWS;
    for (x; x < end_row; x++) {
        total_row += matrix[x];
    }
    printf("The total in row %d is %d \n", index, total_row);
}

void createMatrix(int *matrix) {
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        matrix[i] = i;
    }
}

void displayMatrix(int *matrix) {
    int x = 0;
    int row_size = MATRIX_ROWS;

    printf("Matrix :\n");
    for (int i = 0; i < MATRIX_COLUMNS; i++)
    {
        for (x; x < row_size; x++) {
            printf("%d ", matrix[x]);
        }
        row_size += MATRIX_ROWS;
        printf("\n");
    }
    printf("\n");
}
