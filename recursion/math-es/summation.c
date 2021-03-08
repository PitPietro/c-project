#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

// recursive_summ takes in a function as parameter
int recursive_summ(double (*f)(double x), int m, int n) {
    printf("m = %d ~ f(m) = %lf\n", m, (*f)(m));

    // everything starts from a for loop
    if(m == n) {
        return (*f)(m);
    } else {
        return (*f)(m) + recursive_summ(f, m+1, n);
    }
}

double iterative_summ_v0(double (*f)(double x), int m, int n) {
    // everything starts from a for loop
    int i;
    double result = 0;

    for(i = m; i <= n; i++) {
        result += (*f)(i);
    }

    return result;
}

double iterative_summ(int m, int n) {
    // then it comes to a while loop
    // 'i' can be replaced by 'm' itself
    double result = 0;

    while(m <= n) {
        result += f_square(m);
        m++;
    }

    return result;
}

double tail_summ(int m, int n, double res) {
    double result = res;

    if(m <= n) {
        result += f_square(m);
        m++;

        return tail_summ(m, n, result);
    }

    return result;
}

int main() {
    int lower = 1;
    int upper = 4;

    double recSumm = recursive_summ(f_1, lower, upper);
    double interSummFor = iterative_summ_v0(f_const, lower, upper);
    double interSumm = iterative_summ(lower, upper);
    double tailSumm = tail_summ(lower, upper, 0);

    char msg[] = "Summation of f(i) from i =";
    printf("%s %d to %d is %lf\n", msg, lower, upper, recSumm);
    printf("%s %d to %d is %lf\n", msg, lower, upper, interSummFor);
    printf("%s %d to %d is %lf\n", msg, lower, upper, interSumm);
    printf("%s %d to %d is %lf\n", msg, lower, upper, tailSumm);

    return 0;
}

// cd recursion/math-es
// gcc -o summ summation.c functions.c && ./summ

/*
Copy/Past the following line in any LaTeX editor:
```latex
\sum_{i = m}^n f(i)
```

i is the index of summation
m is the lower bound of summation
n is the upper bound of summation
*/