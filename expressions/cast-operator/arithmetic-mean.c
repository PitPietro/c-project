#include <stdio.h>

int main() {
    int a, b;
    float mean;
    
    a = 3;
    b = 7;
    mean = (a + b) / 2.0;

    printf("Mean between %d and %d is %f\n", a, b, mean);
}

/*
TODO Make the mean for an array of integer
int array[n];

float mean = (array[0] + array[1] + ... + array[n-1]) / (float) n;
*/

// cd expressions/cast-operator
// gcc -o am arithmetic-mean.c && ./am