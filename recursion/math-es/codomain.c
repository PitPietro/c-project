#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#define N 10

int find_codomain(double (*f)(double x), int a, int b, double codomain[N]) {
    int i, dim = 0;

    for(i = a; i <= b; i++) {
        codomain[dim] = (*f)((double)i);

        printf("x = %d ~ f(%d) = %lf ~ index = %d\n", i, i, codomain[dim], dim);

        dim++;
    }

    return dim;
}

void print_codomain(double codomain[N], int dim) {
    int i;

    for(i = 0; i < dim; i++) {
        printf("%lf\t", codomain[i]);
    }

    printf("\n");
}

int main() {
    double cod[N];

    int dimension = find_codomain(f_square, 0, 5, cod);
    print_codomain(cod, dimension);

    return 0;
}

/*
return the codomain of a function in a given interval I = [a, b], a < b
considering all the natural numbers from a to b (included)
*/

// cd recursion/math-es
// gcc -o cod codomain.c functions.c && ./cod