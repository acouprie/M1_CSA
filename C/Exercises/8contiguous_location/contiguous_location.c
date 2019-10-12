#include <stdio.h>

int main(int argc, char *argv[]) {
    int integers[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("Number of bites per item : %d \n", sizeof(integers[0]));
    for(int i=0; i < sizeof(integers)/sizeof(integers[0]); i++) {
        printf("Adress %d: ", i);
        printf("%d \n", &integers[i]);
    }
}
