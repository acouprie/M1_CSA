#include <stdlib.h>
#include <stdio.h>

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

void print_data(int *tableau, int taille) {
	for( int i=0; i<taille; ++i)
		printf( "%d ", tableau[i] );
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

	/* output result */

	/* end of the program*/
	free(data);
	return 0;
}

