#define MATRIX_ROWS 5
#define MATRIX_COLUMNS 10
#define MATRIX_SIZE MATRIX_ROWS * MATRIX_COLUMNS

void displayMatrix (int *matrix);
void createMatrix (int *matrix);
void computeRows(int *matrix, int index);
void computeTotal(int *matrix);
void *init_thread(int *arg);