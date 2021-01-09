#include <stdio.h>

extern int globalA;

int main() {
    printf("a = %d\n", globalA);
}

// cd lifetime-scope/scope/external-linking
// gcc -o main main.c fun.c && ./main