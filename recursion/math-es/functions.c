#include <stdio.h>

/* functions.c contains all the f(x) usefull functions the other files of this folder use */

// f(x) = x
double f_const(double x) {
    return x;
}

// f(x) = x^2
double f_square(double x) {
    return x * x;
}

// x^2 + 5x + 2
double f_1(double x) {
    return (x * x) + (5 * x) + 2;
}

// cd recursion/math-es