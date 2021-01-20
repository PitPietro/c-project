#include <stdio.h>
#include <stdlib.h>
#include "sorting-utils.h"

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

    return 0;
}


// cd sorting-algorithms/
// gcc -o insertion insertion.c sorting-utils.c && ./insertion