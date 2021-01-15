#include <stdio.h>
#include <stdlib.h> 

short readShortInt() {
    short tmp;
    printf("~ please insert an int: ");
    scanf("%hd", &tmp);
    return tmp;
}

void readShortIntByValue(short *tmp) {
    printf("~ please insert an int (by value): ");
    scanf("%hd", tmp);
}

int main() {
    short a, b, c;
    a = readShortInt();
    b = readShortInt();
    readShortIntByValue(&c);

    printf("\na = %hd\nb = %hd\nc = %hd\n", a, b, c);
}

// cd input-output
// gcc -o read-number read-number.c && ./read-number