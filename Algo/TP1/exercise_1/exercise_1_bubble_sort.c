#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * Reading and writing data
 */
void read_data( FILE *datain, int **dataout, int *n, int *k ) {
	int *data;

	fscanf(datain, "%d", n);
	fscanf(datain, "%d", k);
	*dataout = (int *)malloc( (*n) * sizeof(int) );
	data=*dataout;

	for ( int i=0; i< *n; ++i, ++data )
		fscanf( datain, "%d", data );
}

void print_data(int *array, int size) {
	for( int i=0; i<size; ++i)
		printf( "%d ", array[i] );
	printf("\n");
}

/**
 * Exchange values between two memory space
 */
void permut(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/* Write your functions there*/
void bubble_sort(int *array, int size, int k) {
	for (int j = 0; j < k; j++)
	{
		for (int i = size - 1; i > 0; i--)
		{
			if(array[i] > array[i-1]) {
				int temp = array[i];
				array[i] = array[i-1];
				array[i-1] = temp;
			}
		}
	}
}

int percolateDown(int *array, int size, int index) {
    int m;
    int l = left(index);
    int r = right(index);
    if(l <= size && array[index-1] < array[l-1]) {
        m = l;
    } else {
        m = index;
    }
    if(r <= size && array[m-1] < array[r-1]) {
        m = r;
    }
    if(m != index) {
        permut(&array[index-1], &array[m-1]);
        percolateDown(array, size, m);
    }
}
int remove_n(int *array, int *size, int nb_of_element) {
    if(*size < 1) {
        printf("Error remove");
        exit(0);
    } 
    for (int i = 0; i < nb_of_element; i++)
    {
        int m = array[0];
        array[0] = array[*size - 1];
        *size = *size - 1;
        percolateDown(array, *size, 1);
    }
}

/* Main Program*/
int main( int argc, char **argv ) {
	int *data;
	int n, k;
	FILE *f_in;

	if ( argc > 1 )
		f_in = fopen(argv[1], "r");
	else
		f_in = stdin;

	/* read the data from the file given in arg or from stdin */
	read_data( f_in, &data, &n, &k );
	fclose(f_in);

	/* print the array */

	/* use your functions there*/
	clock_t duree = clock();
	double duree_ms;

	bubble_sort(data,n,k);
	remove_n(data, n, k);
	print_data(data,k);

	duree = clock() - duree;
	duree_ms = duree/(double)CLOCKS_PER_SEC*1000;
	printf("Bubble sort done in %.7fms\n", duree_ms);
	/* output result */

	/* end of the program*/
	free(data);
	return 0;
}


