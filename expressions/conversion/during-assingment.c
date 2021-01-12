#include <stdio.h>

int main() {
    char c = 110;
    short s;
    float f;

    // c: char --> short
    s = c + 10;
    printf("s: %d\n", s);

    // c: char --> short --> --> int --> float
    f = c;
    printf("f: %f\n", f);

    f = 15.8;

    // truncation: 0.8 will be lost
    s = f;
    printf("f: %f \t s: %d\n", f, s);
}

// cd expressions/conversion
// gcc -o da during-assingment.c && ./da