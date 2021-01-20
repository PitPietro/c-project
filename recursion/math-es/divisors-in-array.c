#include <stdio.h>
#include <stdlib.h>

#define MAX 10


int recursive_divisor_array(int numbers[], int div, int last) {
    if (last < 0) {
        return 0;
    } else if(numbers[last] % div == 0) {
        return 1 + recursive_divisor_array(numbers, div, last - 1);
    } else if(numbers[last] % div != 0) {
        return 0 + recursive_divisor_array(numbers, div, last - 1);
    }
}

int iterative_divisor_array_v0(int numbers[], int div, int last) {
    int i;
    int res = 0;

    for(i = 0; i <= last; i++) {
        if(numbers[i] % div == 0) {
            res += 1;
        }
    }

    return res;
}

int iterative_divisor_array(int numbers[], int div, int last) {
    int i = 0;
    int res = 0;

    while(i <= last) {
        if(numbers[i] % div == 0) {
            res += 1;
        }

        i++;
    }

    return res;
}

int tail_divisor_array(int numbers[], int div, int last, int iterator, int result) {
    int i = iterator;
    int res = result;

    if(i <= last) {
        if(numbers[i] % div == 0) {
            res += 1;
        }
        i++;

        return tail_divisor_array(numbers, div, last, i, res);
    }

    return res;
}

int main() {
    int array[MAX] = {27, 9, 3, 4, 5, 6, 7, 8, 9, 10};
    int d = 3;
    int l = 5;

    int recDiv = recursive_divisor_array(array, d, l);
    int iterDivFor = iterative_divisor_array_v0(array, d, l);
    int iterDiv = iterative_divisor_array(array, d, l);
    int tailDiv = tail_divisor_array(array, d, l, 0, 0);

    printf("%d\t recursive\n", recDiv);
    printf("%d\t iterative for-loop\n", iterDivFor);
    printf("%d\t iterative while-loop\n", iterDiv);
    printf("%d\t tail recursive\n", tailDiv);
    return 0;
}

// cd recursion/math-es
// gcc -o div-in-array divisors-in-array.c && ./div-in-array

// find the divisors of 'div' in numbers[] array from 0 to 'last'