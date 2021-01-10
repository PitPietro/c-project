#include <stdio.h>

const short int charBit = 8;

unsigned char maxChar() {
    // returns 2^8 - 1
    short int i;
    unsigned char result = 1;
    for(i = 0; i < charBit; i++) {
        result *= 2;
    }

    return result - 1;
}

int main() {
    unsigned char a, b;

    a = maxChar();
    b = a + 1;

    // overlow: 255 + 1 = 0
    printf("a = %d\n", a);
    printf("%d + 1 = %d\n", a, b); 

}

// cd expressions
// gcc -o overflow overflow.c && ./overflow