#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    // exit condition
    if(n == 0) {
        return 1;
    } else {
        return n + factorial(n-1);
    }
}

int main() {
    int a = 10;
    int result = factorial(a);

    printf("The factorial of %d is %d\n", a, result);

    return 0;
}

// cd recursion/math-es
// gcc -o fact factorial.c && ./fact