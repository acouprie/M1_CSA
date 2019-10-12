#include <stdio.h>
#include <ctype.h>

/*
    Recreate the Caeser code, where a letter is transposed to letter-key in alphabet, ex :
    key = 3
    input = abcdefg
    output = xyzabcd

    TODO :
    - handle space
    - handle uppercase
    - extract main's body to function
*/

#define ALPHABET_LENTGH 26

int main(void){
    char alphabet[ALPHABET_LENTGH] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char input[256];
    char result[256];
    int inputLength = 0;
    int key = 3;

    // get input
    printf("Enter a sentence : \n");
    scanf("%s", input);

    // mesure the lentgh of the string
    for (inputLength; input[inputLength] != '\0'; inputLength++);

    for(int position = 0; input[position] != '\0'; position++) {
        // check if it is alphanumeric char
        if (isalpha(input[position])) {
            // loop over the alphabet
            for (int letterIndex = 0; alphabet[letterIndex] != '\0'; letterIndex++) {
                // if the cipher goes too much on left, go to the end of the alphabet array
                if (input[position] == alphabet[letterIndex] && letterIndex < key) {
                    result[position] = alphabet[ALPHABET_LENTGH + letterIndex - key];
                }
                // else just use the cipher to the left
                else if (input[position] == alphabet[letterIndex]) {
                    result[position] = alphabet[letterIndex - key];
                }
            }
            result[inputLength] = '\0';
        // if not a letter, just insert it
        } else {
            result[position] = input[position];
        }
    }

    // loop over the result string and print it
    for (int i = 0; result[i] != '\0'; i++) {
        printf("%c", result[i]);
    }
    printf("\n");

    return(0);
}