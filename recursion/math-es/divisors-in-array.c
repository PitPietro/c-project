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

int iterative_divisor_array_v0(int numbers[]) {
    // ...
}

int iterative_divisor_array(int numbers[]) {
    // ...
}

int tail_divisor_array(int numbers[], int iterator, int result) {
    // ...
}

int main() {
    int array[MAX] = {27, 9, 3, 4, 5, 6, 7, 8, 9, 10};

    int recDiv = recursive_divisor_array(array, 3, 5);
    int iterDivFor = iterative_divisor_array_v0(array);
    int iterDiv = iterative_divisor_array(array);
    int tailDiv = tail_divisor_array(array, 0, 0);

    printf("%d\t recursive\n", recDiv);
    /*
    printf("%d\t iterative for-loop\n", iterDivFor);
    printf("%d\t iterative while-loop\n", iterDiv);
    printf("%d\t tail recursive\n", tailDiv);
    */
    return 0;
}

// cd recursion/math-es
// gcc -o div-in-array divisors-in-array.c && ./div-in-array

// find the divisors of 'div' in numbers[] array from 0 to 'last'