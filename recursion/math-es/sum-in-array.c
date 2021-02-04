#include <stdio.h>
#include <stdlib.h>

#define MAX 10


int recursive_sum_array(int numbers[], int first) {
    // if(first == MAX) is wrong since number[MAX] does not exist
    if(first == MAX-1) {
        return numbers[first];
    } else {
        return numbers[first] + recursive_sum_array(numbers, first+1);
    }
}

int iterative_sum_array_v0(int numbers[]) {
    int i, result = 0;

    for(i = 0; i < MAX; i++) {
        result += numbers[i];
    }

    return result;
}

int iterative_sum_array(int numbers[]) {
    int i = 0;
    int result = 0;

    while(i < MAX) {
        result += numbers[i];
        i++;
    }

    return result;
}

int tail_sum_array(int numbers[], int iterator, int result) {
    int i = iterator;
    int res = result;

    if(i < MAX) {
        res += numbers[i];
        i++;

        return tail_sum_array(numbers, i, res);
    }

    return res;
}

int main() {
    int array[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int recSum = recursive_sum_array(array, 0);
    int iterSumFor = iterative_sum_array_v0(array);
    int iterSum = iterative_sum_array(array);
    int tailSum = tail_sum_array(array, 0, 0);

    printf("%d\t recursive\n", recSum);
    printf("%d\t iterative for-loop\n", iterSumFor);
    printf("%d\t iterative while-loop\n", iterSum);
    printf("%d\t tail recursive\n", tailSum);
    
    return 0;
}

// cd recursion/math-es
// gcc -o sum-in-array sum-in-array.c && ./sum-in-array

// sum all the elements in the array