#include <stdio.h>
#include <stdlib.h>   
#include <time.h>

/*
    Throw 6 dices
*/

int main(void) {
    srand(time(NULL));
    for(int i=0; i<6; i++) {
        printf("%d\n", rand() % 6) + 1;
    }

    return 0;
}