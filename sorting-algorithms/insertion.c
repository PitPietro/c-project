#include <stdio.h>
#include <stdlib.h>
#include "sorting-utils.h"

void insertion_sort_recursive(int numbers[], int size) { 

    if (size <= 1) {
        return;
    }

    // sort first n-1 elements 
    insertion_sort_recursive(numbers, size - 1);

    // insert last element at its correct position in sorted array. 
    int last = numbers[size - 1];
    int i = size - 2;

    /* move elements of numbers[0..i-1], that are 
      greater than key, to one position ahead 
      of their current position
    */
    
    while (i >= 0 && numbers[i] > last) { 
        numbers[i+1] = numbers[i]; 
        i--;

        print_array(numbers, size);
        printf("|  i = %d  |  size = %d  |  n[%d] = %d\n", i, size, i, numbers[i]);
    }

    numbers[i+1] = last;

    print_array(numbers, size);
    printf("|  i = %d  |  size = %d  |  n[%d] = %d\n", i, size, i, numbers[i]);
}

void insertion_sort(int numbers[], int size) {
    int i, j, key;

    for(i = 1; i < size; i++) {
        key = numbers[i];
        j = i - 1;

        // Move elements of numbers[0 ... i-1], that are greater than 'key',
        // to one position ahead of their current position

        while (j >= 0 && numbers[j] > key) {
            numbers[j + 1] = numbers[j];
            j -= 1;

            print_array(numbers, size);
        printf("|  i = %d  |  j = %d\t|  key = %d  |  n[%d] = %d  |  n[%d + 1] = %d\n", i, j, key, i, numbers[i], j, numbers[j + 1]);
        }

        numbers[j + 1] = key;  

        print_array(numbers, size);
        printf("|  i = %d  |  j = %d\t|  key = %d  |  n[%d] = %d  |  n[%d + 1] = %d\n", i, j, key, i, numbers[i], j, numbers[j + 1]);
    }
}

int main() {
    int arr[] = {89, 61, 33, 24, 15, 18, 11, 10}; 
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted array:\n");
    print_array(arr, n);
    printf("\n~~~~~\n");

    insertion_sort(arr, n);

    printf("~~~~~\n");
    printf("Sorted array:\n");
    print_array(arr, n);
    printf("\n");

    printf("\nInsertion sort recursive:\n");
    int arr2[] = {89, 61, 33, 24, 15, 18, 11, 10}; 
    int n2 = sizeof(arr2)/sizeof(arr2[0]);


    printf("Unsorted array:\n");
    print_array(arr2, n2);
    printf("\n~~~~~\n");

    insertion_sort_recursive(arr2, n2);

    printf("~~~~~\n");
    printf("Sorted array:\n");
    print_array(arr2, n2);
    printf("\n");


    return 0;
}


// cd sorting-algorithms/
// gcc -o insertion insertion.c sorting-utils.c && ./insertion