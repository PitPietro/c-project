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

double iterative_pow_v2(double b, int exp) {
    // no need for 'i' variable
    double res = 1;

    while(exp > 0) {
        res *= b;
        exp--;
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

double tail_pow_v2(double b, int exp, double result) {
    double res = result;

    if(exp > 0) {
        return tail_pow_v2(b, exp - 1, res * b);
    }

    return res;
}

int main() {
    int base = 2;
    int exponent = 4;

    double recPow = recursive_pow(base, exponent);
    double iterPow = iterative_pow(base, exponent);
    double iterPow2 = iterative_pow_v2(base, exponent);
    double tailPow = tail_pow(base, exponent, 1, 1);
    double tailPow2 = tail_pow_v2(base, exponent, 1);

    printf("%d^%d = %lf\t recursive\n", base, exponent, recPow);
    printf("%d^%d = %lf\t iterative v1\n", base, exponent, iterPow);
    printf("%d^%d = %lf\t iterative v2\n", base, exponent, iterPow2);
    printf("%d^%d = %lf\t tail recursive v1\n", base, exponent, tailPow);
    printf("%d^%d = %lf\t tail recursive v2\n", base, exponent, tailPow2);
    
    return 0;
}

// cd recursion/math-es
// gcc -o pow pow.c && ./pow

/*
You can also change the 'base' type to any numerical type you want
(lower or equal 'double', or you'll need to change the function argument's type).
Be sure to change the placeholders accordingly.
*/