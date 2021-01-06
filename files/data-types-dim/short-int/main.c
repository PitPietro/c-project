#include "short-int.h"

int main() {
    short int x = 32134;
    short int y = 14230;

    write_short_int_to_bin(x);
    write_short_int_to_txt(y);

    return 0;
}

// cd files/data-types-dim/short-int
// gcc -o main main.c short-int.c && ./main