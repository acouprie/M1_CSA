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
	print_data(data,n);

	/* use your functions there*/
	clock_t duree = clock();
	double duree_ms;

	bubble_sort(data,n,k);
	print_data(data,k);

	duree = clock() - duree;
	duree_ms = duree/(double)CLOCKS_PER_SEC*1000;
	printf("Bubble sort done in %.7fms\n", duree_ms);
	/* output result */

	/* end of the program*/
	free(data);
	return 0;
}


