#include <stdio.h>
#include <stdlib.h>

long factorial(int n) {
    if(n == 0) {
        // exit condition
        return 1;
    } else {
        // recursion
        return n * factorial(n-1);
    }
}

long iterative_factorial(int n) {
    int i = 1;
    long result = 1;

    while(i <= n) {
        result *= i; // result = result * i
        i++;
    }

    return result;
}

long tail_fact(int n, int iterator, long result) {
    int i = iterator;
    long res = result;

    while(i <= n) {
        res *= i;
        i++;
        return tail_fact(n, i, res);
    }

    return res;
}

int main() {
    int a;   

    printf("Insert the number you want to evaluate the factorial of: ");
    scanf("%d", &a);

    long result = factorial(a);
    long iterRes = iterative_factorial(a);
    long tailRes = tail_fact(a, 1, 1);

    printf("The factorial of %d is %ld\n", a, result);
    printf("The factorial of %d is %ld\n", a, iterRes);
    printf("The factorial of %d is %ld\n", a, tailRes);

    return 0;
}

// cd recursion/math-es
// gcc -o fact factorial.c && ./fact

/*
Evaluates the factorial of a given number.
The return type of the funcions is 'long' since the result could be very huge.
While the user input is an int, since it could be very difficult to evaluate
the factorial of a 'long' number.
*/