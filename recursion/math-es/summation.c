#include <stdio.h>
#include <stdlib.h>

int f_const(int x) {
    // f(x) = x
    return x;
}

int f_pow(int x) {
    // f(x) = x^2
    return x * x;
}

// recursive_summ takes in a function as parameter
int recursive_summ(int (*f)(int x), int m, int n) {
    printf("m = %d ~ f(m) = %d\n", m, (*f)(m));

    // everything starts from a for loop
    if(m == n) {
        return (*f)(m);
    } else {
        return (*f)(m) + recursive_summ(f, m+1, n);
    }
}

int iterative_summ_v0(int (*f)(int x), int m, int n) {
    // everything starts from a for loop
    int i;
    int result = 0;

    for(i = m; i <= n; i++) {
        result += (*f)(i);
    }

    return result;
}

int iterative_summ(int m, int n) {
    // then it comes to a while loop
    // 'i' can be replaced by 'm' itself
    int result = 0;

    while(m <= n) {
        result += f_pow(m);
        m++;
    }

    return result;
}

int tail_summ(int m, int n, int res) {
    int result = res;

    if(m <= n) {
        result += f_pow(m);
        m++;

        return tail_summ(m, n, result);
    }

    return result;
}

int main() {
    int lower = 1;
    int upper = 4;

    int recSumm = recursive_summ(f_const, lower, upper);
    int interSummFor = iterative_summ_v0(f_const, lower, upper);
    int interSumm = iterative_summ(lower, upper);
    int tailSumm = tail_summ(lower, upper, 0);

    char msg[] = "Summation of f(i) from i =";
    printf("%s %d to %d is %d\n", msg, lower, upper, recSumm);
    printf("%s %d to %d is %d\n", msg, lower, upper, interSummFor);
    printf("%s %d to %d is %d\n", msg, lower, upper, interSumm);
    printf("%s %d to %d is %d\n", msg, lower, upper, tailSumm);

    return 0;
}

// cd recursion/math-es
// gcc -o summ summation.c && ./summ

/*
Copy/Past the following line in any LaTeX editor:
```latex
\sum_{i = m}^n f(i)
```

i is the index of summation
m is the lower bound of summation
n is the upper bound of summation
*/