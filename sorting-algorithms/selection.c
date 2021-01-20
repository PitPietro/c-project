#include <stdio.h>
#include <stdlib.h>
#include "sorting-utils.h"

void selection_sort(int numbers[], int size) {
    int i, j, min;

    for(i = 0; i < size - 1; i++) {
        min = i;

        for(j = i+1; j < size; j++) {
            if(numbers[j] < numbers[min]) {
                min = j;
            }

            print_array(numbers, size);
            printf("|  i = %d  |  j = %d  |  min = %d  |  n[%d] = %d  |  n[%d] = %d  |  n[%d] = %d\n", i, j, min, i, numbers[i], j, numbers[j], min, numbers[min]);
        }

        // swap the found minimum element with the first element 
        swap(&numbers[min], &numbers[i]);
    }
}

int main() {
    int arr[] = {89, 61, 33, 24, 15, 18, 11, 10}; 
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted array:\n");
    print_array(arr, n);
    printf("\n~~~~~\n");

    selection_sort(arr, n);

    printf("~~~~~\n");
    printf("Sorted array:\n");
    print_array(arr, n);
    printf("\n");

    return 0;
}


// cd sorting-algorithms/
// gcc -o selection selection.c sorting-utils.c && ./selection