#include <stdio.h>
#include <stdlib.h>

int f_const(int i) {
    // f(i) = i
    return i;
}

int f_pow(int i) {
    // f(i) = i^2
    return i * i;
}


int recursive_summ(int m, int n) {
    // everything starts from a for loop
    if(m == n) {
        printf("> exit: m = %d ~ m^2 = %d\n\n", m, f_pow(m));
        return f_pow(m);
    } else {
        printf("> else: m = %d ~ m^2 = %d\n", m, f_pow(m));
        return f_pow(m) + recursive_summ(m+1, n);
    }
}

int iterative_summ_v0(int m, int n) {
    // everything starts from a for loop
    int i;
    int result = 0;

    for(i = m; i <= n; i++) {
        result += f_pow(i);
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

    int recSumm = recursive_summ(lower, upper);
    int interSummFor = iterative_summ_v0(lower, upper);
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