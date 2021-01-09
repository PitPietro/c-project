#include <stdio.h>
#include <stdlib.h>
#define DIM 10

// search an element inside an already ordered array
int binary_search(int vector[], int n, int first, int last) {
    int med = (first + last) / 2;

    if (last < first) {
        // error: 'n' is not inside 'vector'
        printf("Last index %d is minor than the first index %d\n", last, first);
        printf("It can not be possible!\n");
        exit(1);
    }
    if (n == vector[med]) {
        // n is equal to vector[med]
        // 1st exit condition: 'n' is at index 'med'
        return med;
    }
    else if (n < vector[med]) {
        // n is minor than vector[med]
        binary_search(vector, n, first, med-1);
    }
    else if (n > vector[med]) {
        // n is major than vector[med]
        binary_search(vector, n, med+1, last);
    }    
}

void print_array(int vector[]) {
    printf("The elements are: \n");
    for(int i = 0; i < DIM; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n\n");
}

int main() {
    int numbers[DIM] = {1, 3, 4, 7, 8, 10, 22, 55, 67, 99};
    int numberToFind = 99;

    print_array(numbers);
    int result = binary_search(numbers, numberToFind, 0, DIM);

    if (result < 0) {
        printf("%d is not inside the array\n", numberToFind);
    } else {
        printf("%d is at index %d\n", numberToFind, result);
    }

    return 0;
}

// cd recursion
// gcc -o binary-search binary-search.c && ./binary-search