#include <stdio.h>
#include <stdlib.h>

double recursive_pow(double b, int exp) {
    if(exp == 1) {
        return b;
    } else {
        return b * recursive_pow(b, exp-1);
    }
}

double iterative_pow(double b, int exp) {
    int i = 1;
    double res = 1;

    while(i <= exp) {
        res *= b;
        i++;
    }

    return res;
}

double tail_pow(double b, int exp, int iterator, double result) {
    int i = iterator;
    double res = result;

    if(i <= exp) {
        res *= b;
        i++;

        return tail_pow(b, exp, i, res);
    }

    return res;
}

int main() {
    int base = 2;
    int exponent = 4;

    double recPow = recursive_pow(base, exponent);
    double iterPow = iterative_pow(base, exponent);
    double tailPow = tail_pow(base, exponent, 1, 1);

    printf("%d^%d = %lf\n", base, exponent, recPow);
    printf("%d^%d = %lf\n", base, exponent, iterPow);
    printf("%d^%d = %lf\n", base, exponent, tailPow);
}

// cd recursion/math-es
// gcc -o pow pow.c && ./pow

/*
You can also change the 'base' type to any numerical type you want
(lower or equal 'double', or you'll need to change the function argument's type).
Be sure to change the placeholders accordingly.
*/