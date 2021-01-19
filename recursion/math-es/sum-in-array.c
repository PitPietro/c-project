#include <stdio.h>
#include <stdlib.h>

#define MAX 10

/*
int recursive_sum_array(int numbers[], int first, int last) {
    if(first == last) {
        return numbers[last];
    } else {
        return numbers[first] + recursive_sum_array(numbers, first+1, last);
    }
}
*/

int iterative_sum_v0(int numbers[], int size) {
    int i, result = 0;

    for(i = 0; i < size; i++) {
        result += numbers[i];
    }

    return result;
}

int iterative_sum(int numbers[], int size) {
    int i = 0;
    int result = 0;

    while(i < size) {
        result += numbers[i];
        i++;
    }

    return result;
}

int tail_sum(int numbers[], int size, int iterator, int result) {
    int i = iterator;
    int res = result;

    while(i < size) {
        res += numbers[i];
        i++;

        return tail_sum(numbers, size, i, res);
    }

    return res;
}

int main() {
    int array[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // int recSum = recursive_sum_array(array, 0, MAX);
    int iterSumFor = iterative_sum_v0(array, MAX);
    int iterSum = iterative_sum(array, MAX);
    int tailSum = tail_sum(array, MAX, 0, 0);

    // printf("%d\t recursive\n", recSum);
    printf("%d\t iterative for-loop\n", iterSumFor);
    printf("%d\t iterative while-loop\n", iterSum);
    printf("%d\t tail recursive\n", tailSum);
    
    return 0;
}

// cd recursion/math-es
// gcc -o sum-in-array sum-in-array.c && ./sum-in-array

// sum all the elements in the array