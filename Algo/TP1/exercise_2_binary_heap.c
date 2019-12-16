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
        printf("%i", i);
		//printf("%d", array[i]);
	printf("\n");
}

int parent(int index) {
    return index / 2;
}

int left(int index) {
    return 2 * index;
}

int right(int index) {
    return 2 * index + 1;
}

void permut(int *first_element, int *second_element) {
    int temp = *first_element;
    *first_element = *second_element;
    *second_element = temp;
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

int buildHeap(int *array, int size) {
    if(size < 1) {
        printf("Error build heap");
        exit(0);
    }
    for(int i = size / 2; i >= 1; i--) {
        percolateDown(array, size, i);
    }
}

int remove_first(int *array, int *size) {
    if(*size < 1) {
        printf("Error remove");
        exit(0);
    } 
    int m = array[0];
    array[0] = array[*size - 1];
    *size = *size - 1;
    percolateDown(array, *size, 1);
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

int percolateUp(int *array, int i) {
    int j = parent(i);
    while(j > 0 && array[j - 1] < array[i - 1]) {
        permut(&array[i - 1], &array[j - 1]);
        i = j;
        j = parent(i);
    }
}

int add(int *array, int *size, int element_to_add) {
    *size = *size + 1;
    array[*size - 1] = element_to_add;
    percolateUp(array, *size);
}

int build_from_scratch(int *empty_array, int *array, int *n, int k) {
    int element_to_add;
    int size = 0;
    for (int i = 0; i < *n; i++)
    {
        element_to_add = array[i];
        add(empty_array, &size, element_to_add);
    }
    remove_n(empty_array, &size, k);
    printf("Build from scratch: ");
	print_data(empty_array, size);
}

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
 //   printf("Input data: ");
	//print_data(data,n);

	//clock_t duree = clock();
 //   double duree_ms;
 //   /* use your functions there*/
	//buildHeap(data, n);
 //   printf("Builded heap: ");
	//print_data(data,n);
 //   duree = clock() - duree;
	//duree_ms = duree/(double)CLOCKS_PER_SEC*1000 ;
	//printf("Build heap done in %.7fms\n", duree_ms);

    // 1
    //remove_first(data, &n);
    // 2
    //remove_n(data, &n, 3);

    //add(data, &n, 60);

    //int empty_array[n + 5];

    //duree = clock();
    //build_from_scratch(empty_array, data, &n, k);
    //duree = clock() - duree;
    //duree_ms = duree/(double)CLOCKS_PER_SEC*1000 ;
    //printf("Build from scratch done in %.7fms\n", duree_ms);

	/* output result */
    //printf("Output: ");
	//print_data(data, n);

	/* end of the program*/
	free(data);
	return 0;
}