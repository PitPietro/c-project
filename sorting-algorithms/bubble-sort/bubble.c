
#include <stdio.h>
#include <stdlib.h>

void swap(int * x, int * y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void print_array(int numbers[], int size) {
    int i;

    // printf("\nThe array elements are:\n");
    for(i = 0; i < size; i++) {
        printf("%d\t", numbers[i]);
    }
}

void bubble_sort_for(int numbers[], int size) {
    int i, j;

    for(i = 0; i < size - 1; i++) {
        for(j = 0; j < size - i - 1; j++) {
            if(numbers[j] > numbers[j + 1]) {
                swap(&numbers[j], &numbers[j + 1]);
            }
            print_array(numbers, size);

            printf("|  i = %d  |  j = %d  |  n[%d] = %d  |  n[%d] = %d\n", i, j, i, j, numbers[i], numbers[j]);
        }
    }
}

int main() {
    int arr[] = {89, 61, 33, 24, 15, 18, 3, 0}; 
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted array:\n");
    print_array(arr, n);
    printf("\n~~~~~\n");

    bubble_sort_for(arr, n);

    printf("~~~~~\n");
    printf("Sorted array:\n");
    print_array(arr, n);
    printf("\n");

    return 0;
}


// cd sorting-algorithms/bubble-sort
// gcc -o bubble bubble.c && ./bubble