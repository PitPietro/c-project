#include <stdio.h>
#include "uppercase.h"

int main() {
    make_uppercase();
    return 0;
}

// cd files/fseek/txt-files
// gcc -o main main.c uppercase.c && ./main

/*
In text files, there is a mismatch between the file characters and the text characters.
i.e. in Windows the break line character takes up two characters.

Each record of the same data type (or the same struct), could take up a a different number of bytes.
This example shows how to correctly use 'fseek()' to replace the letters (one by one)
with thier corresponding uppercase.
*/