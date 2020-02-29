#include <stdio.h>

int main(int argc, char *argv[]){
    //step 1:
    int c;
    FILE* file = NULL;
    file = fopen("lorem.txt", "r+");
    //step 2:
    if ( file != NULL){
    //step 3:
    while ((c = getc(file)) != EOF) {
        putchar(c);
    }
    printf("\n");
    //step 4:
    fclose(file);
    } else {
        printf("Impossible to open the file test.txt \n");
    }
}