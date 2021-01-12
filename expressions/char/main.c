#include <stdio.h>
#include "alphabet.h"

void ascii() {
    // In ASCII, from 0 to 32 there are the so called "transparent codes"
    unsigned char i, c = 33;

    for(i = c; i < 128; i++) {
        printf("%c\t%d\n", i, i);
    }

    c = 9;
    printf("tab:%c code n°: %d\n", c, c);
    c = 10;
    printf("break line:%c code n°: %d\n", c, c);
    c = 32;
    printf("space: |%c| code n°: %d\n", c, c);

    placeholderUppercase();
    placeholderLowercase();
    castToIntUppercase();
    castToIntLowercase();
}

int main() {
    ascii();    
}

// cd expressions/char
// gcc -o main main.c alphabet.c && ./main