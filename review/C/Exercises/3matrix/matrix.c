#include <stdio.h>
#include <stdbool.h>

/* 
    Transpose a matrix
*/

void printMatrix(int columns, int rows, bool transposed) {
    char rowLabel[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int letter, positionIndex;

    for(int row = 1; row <= rows; row++) {
        for(int col = 1; col <= columns; col++) {
            if (transposed == true) {
                letter = col - 1;
                positionIndex = row;
            } else {
                letter = row - 1;
                positionIndex = col;
            }
            printf("%c", rowLabel[letter]);
            printf("%d ", positionIndex);
        }
        printf("\n");
    }
}

int main(void) {
    int columns, rows;
    columns = 0;
    rows = 0;

    printf("Enter the number of column : \n");
    scanf("%d", &columns);
    printf("Enter the number of row : \n");
    scanf("%d", &rows);

    if (columns > 6 || rows > 6) {
        printf("Maximum size of the matrix : 6*6\nExiting ...\n");
        return(0);
    }

    printf("Original matrix : \n");
    printMatrix(columns, rows, false);
    printf("\nTransposed : \n");
    printMatrix(rows, columns, true);

    return(0);
}