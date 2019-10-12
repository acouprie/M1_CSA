#include <stdio.h>

/*
    Do basic computation in C
*/

int sum(int a, int b) {
    return a + b;
}

int substract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    float result = (float) a / b;
    return result;
}

int modulo(int a, int b) {
    return a % b;
}

int main(void){
    int a, b;
    printf("Enter first number : ");
    scanf("%d", &a);
    printf("Enter second number : ");
    scanf("%d", &b);
    printf("Sum = %d \n", sum(a, b));
    printf("Substract = %d \n", substract(a, b));
    printf("Multiply = %d \n", multiply(a, b));
    printf("Divide = %f \n", divide(a, b));
    printf("Modulo = %d \n", modulo(a, b));

    return 0;
}