#include <stdio.h>
void cuttingMinutes(int *hours, int *minutes);

int main(int argc, char *argv[]){
    int hours = 0, minutes = 90;
    /* We have a variable minutes which is 90.
    After calling the function, I want my variable
    "hours" to be 1 and my variable "minutes" to be 30 */
    cuttingMinutes(&hours, &minutes);
    printf("%d heures et %d minutes \n", hours, minutes);
    return 0;
}

void cuttingMinutes(int *hours, int *minutes) {
    while (*minutes > 60)
    {
        *hours += 1;
        *minutes -= 60;
    }
}
