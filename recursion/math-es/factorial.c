#include <stdio.h>
#include <stdlib.h>

long factorial(int n) {
    // exit condition
    if(n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}


long tail_fact(int n) {
    long res = 1;
    int i = 1;

    while(i <= n) {
        res *= i;
        i++;
    }

    return res;
}

int main() {
    int a;   

    printf("Insert the number you want to evaluate the factorial of: ");
    scanf("%d", &a);

    long result = factorial(a);
    long tailRes = tail_fact(a);

    printf("The factorial of %d is %ld\n", a, result);
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