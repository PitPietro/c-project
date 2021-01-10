#include <stdio.h>

char minChar(short int bit) {
    // returns 2^7 * (-1)
    short int i;
    char result = 1;

    for(i = 0; i < bit-1; i++) {
        result *= 2;
    }

    return result * (-1);
}

char maxChar(short int bit) {
    // returns 2^7 - 1
    short int i;
    char result = 1;

    for(i = 0; i < bit-1; i++) {
        result *= 2;
    }

    return result -1;
}

void signedCharOverflow() {
    short int mBit = 8;
    char a, b;

    a = maxChar(mBit);
    b = a + 1;

    printf("\nSigned char overflow:\n");
    // overlow: 127 + 1 = 0
    printf("a = %d\n", a);
    printf("%d + 1 = %d\n", a, b);

    a = minChar(mBit);
    b = a - 1;

    // overlow: 0 - 1 = -128
    printf("\na = %d\n", a);
    printf("%d - 1 = %d\n", a, b);
}