#include <stdio.h>
int main(void){
    /* my first program in C */
    int i = 1;
    int *p = &i;
    printf("address of i %x \n", &i);
    printf("pointer %x \n", p);
    printf("pointer value %d \n\n", *p);

    int arr[5];
    arr[0]=10;
    arr[1]=20;
    printf("%d \n", arr[0]);

    return 0;
}