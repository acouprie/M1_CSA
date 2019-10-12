#include <stdio.h>

int main(int argc, char *argv[]){
    int integers[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int input = 0;

    printf("Enter a digit : \n");
    scanf("%d", &input);

    for(int i=0; i < sizeof(integers)/sizeof(integers[0]); i++) {
        if (integers[i] > input) {
            integers[i] = 0;
        }
        printf("%d", integers[i]);
    }
}
