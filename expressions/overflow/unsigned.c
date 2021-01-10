#include <stdio.h>

const short int charBit = 8;

unsigned char maxUnsignedChar() {
    // returns 2^8 - 1
    short int i;
    unsigned char result = 1;
    for(i = 0; i < charBit; i++) {
        result *= 2;
    }

    return result - 1;
}

void unsigndCharOverflow() {
    unsigned char a, b;

    a = maxUnsignedChar();
    b = a + 1;

    printf("Unsigned char overflow:\n");
    // overlow: 255 + 1 = 0
    printf("a = %d\n", a);
    printf("%d + 1 = %d\n", a, b);

    a = 0;
    b = a - 1;

    // overlow: 0 - 1 = 255
    printf("\na = %d\n", a);
    printf("%d - 1 = %d\n", a, b);
}