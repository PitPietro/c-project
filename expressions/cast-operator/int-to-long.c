#include <stdio.h>

int main() {
    int i;
    long L;
    
    // 2^15
    i = 32768;
    // 2^16
    L = i * 2;
    printf("2^15 = %d\t2^16 = %ld\n", i, L);

    // 2^16
    i = L;
    // 2^17
    L = ((long) i) * 2;
    printf("2^16 = %d\t2^17 = %ld\n", i, L); 
}

// cd expressions/cast-operator
// gcc -o il int-to-long.c && ./il