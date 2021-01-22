#include <stdio.h>
#include <stdlib.h>
#include "sorting-utils.h"

/*
  merges two subarrays of numbers[].
  first subarray is numbers[left ... middle]
  second subarray is arr[middle + 1 ... right]
*/
void merge(int numbers[], int left, int middle, int right) {
    int leftIndex, rightIndex, k;
    int leftDim = middle - left + 1;
    int rightDim = right - middle;
 
    // create temp arrays
    int L[leftDim], R[rightDim];
 
    // copy data to temp arrays L[] and R[]
    for (leftIndex= 0; leftIndex < leftDim; leftIndex ++)
        L[leftIndex] = numbers[left + leftIndex];
    for (rightIndex = 0; rightIndex < rightDim; rightIndex++)
        R[rightIndex] = numbers[middle + 1 + rightIndex];
 
    // merge the temp arrays back into numbers[left ... right]
    leftIndex = 0; // initial index of first subarray
    rightIndex = 0; // initial index of second subarray
    k = left; // initial index of merged subarray
    
    while (leftIndex < leftDim && rightIndex < rightDim) {
        if (L[leftIndex] <= R[rightIndex]) {
            numbers[k] = L[leftIndex];
            leftIndex++;
        }
        else {
            numbers[k] = R[rightIndex];
            rightIndex++;
        }

        k++;
    }

    // copy the remaining elements of L[] (if there are any)
    while (leftIndex < leftDim) {
        numbers[k] = L[leftIndex];
        leftIndex++;
        k++;
    }
 
    // copy the remaining elements of R[] (if there are any)
    while (rightIndex < rightDim) {
        numbers[k] = R[rightIndex];
        rightIndex++;
        k++;
    }
}

// entry point of the merge sort
void merge_sort(int numbers[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
 
        // sort first and second halves
        merge_sort(numbers, left, middle);
        merge_sort(numbers, middle + 1, right);
 
        merge(numbers, left, middle, right);
    }
}

int main() {
    int arr[] = {89, 61, 33, 24, 15, 18, 11, 10}; 
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("\nMerge sort recursive:\n");
    printf("Unsorted array:\n");
    print_array(arr, n);
    printf("\n~~~~~\n");

    merge_sort(arr, 0, n - 1);

    printf("~~~~~\n");
    printf("Sorted array:\n");
    print_array(arr, n);
    printf("\n");

    return 0;
}


// cd sorting-algorithms/
// gcc -o merge merge.c sorting-utils.c && ./merge