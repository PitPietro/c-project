#include "char.h"

int main() {
    char x = 'A';
    char y = 'a';

    write_char_to_bin(x);
    write_char_to_txt(y);

    return 0;
}

// cd files/data-types-dim/char
// gcc -o main main.c char.c && ./main