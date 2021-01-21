#include <stdio.h>
#include <stdlib.h>
#include "sorting-utils.h"

void bubble_sort_recursive(int numbers[], int size) {
    int i;
    
    // exit condition
    if(size == 1) {
        return;
    }

    // the larges element is moved to end
    for(i = 0; i < size - 1; i++) {
        if(numbers[i] > numbers[i + 1]) {
            swap(&numbers[i], &numbers[i + 1]);
        }

        print_array(numbers, size);
        printf("|  i = %d  |  last = %d\t |  n[%d] = %d\n", i, size, i, numbers[i]);
    }

    print_array(numbers, size);
    printf("|  i = %d  |  last = %d\t |  n[%d] = %d\n", i, size, i, numbers[i]);

    bubble_sort_recursive(numbers, size-1);
}


void bubble_sort(int numbers[], int size) {
    int i, j;

    for(i = 0; i < size - 1; i++) {
        for(j = 0; j < size - i - 1; j++) {
            if(numbers[j] > numbers[j + 1]) {
                swap(&numbers[j], &numbers[j + 1]);
            }

            print_array(numbers, size);
            printf("|  i = %d  |  j = %d  |  n[%d] = %d  |  n[%d] = %d\n", i, j, i, numbers[i], j, numbers[j]);
        }

        print_array(numbers, size);
        printf("|  i = %d  |  j = %d  |  n[%d] = %d  |  n[%d] = %d\n", i, j, i, numbers[i], j, numbers[j]);
    }
}

int main() {
    int arr[] = {89, 61, 33, 24, 15, 18, 11, 10}; 
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted array:\n");
    print_array(arr, n);
    printf("\n~~~~~\n");

    bubble_sort(arr, n);

    printf("~~~~~\n");
    printf("Sorted array:\n");
    print_array(arr, n);
    printf("\n");

    printf("\nBubble sort recursive:\n");
    int arr2[] = {89, 61, 33, 24, 15, 18, 11, 10}; 
    int n2 = sizeof(arr2)/sizeof(arr2[0]);


    printf("Unsorted array:\n");
    print_array(arr2, n2);
    printf("\n~~~~~\n");

    bubble_sort_recursive(arr2, n2);

    printf("~~~~~\n");
    printf("Sorted array:\n");
    print_array(arr2, n2);
    printf("\n");

    return 0;
}


// cd sorting-algorithms/
// gcc -o bubble bubble.c sorting-utils.c && ./bubble

// TODO: Recursive Bubble Sort ~ https://www.geeksforgeeks.org/recursive-bubble-sort/