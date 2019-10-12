#include <stdio.h>
#include <stdbool.h>

// Check if a input word is a palindrom, ex : kayak, laval
bool palindrom(char *input) {
    int inputLength;
    bool is_palindrom = true;

    // Get the size of the string
    for (inputLength = 0; input[inputLength] != '\0'; inputLength++);

    // Check input[0] <=> input[n], input[1] <=> input[n-1]
    for (int positionLeft = 0; positionLeft < inputLength / 2; positionLeft++) {
        if (input[positionLeft] != input[inputLength - positionLeft - 1]) {
            is_palindrom = false;
            break;
        }
    }
    return(is_palindrom);
}

int main(void) {
    char input[256];

    printf("Enter a word : \n");
    scanf("%s", input);

    bool is_palindrom = palindrom(input);
    if (is_palindrom == true) {
        printf("This is a palindrom\n");
    } else {
        printf("This is not a palindrom\n");
    }

    return(0);
}