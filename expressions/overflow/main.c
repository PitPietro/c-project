#include <stdio.h>
#include "unsigned.h"
#include "signed.h"

int main() {
    unsignedCharOverflow();
    signedCharOverflow();

    return 0;
}

// cd expressions/overflow
// gcc -o main main.c unsigned.c signed.c && ./main