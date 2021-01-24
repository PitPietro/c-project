#include <stdio.h>
#include <stdlib.h>

void short_integer() {
    short int arr[] = {90, 1, 15, 7, 11, 44, 65, 25};
    long unsigned int sizeArr = sizeof(arr);
    long unsigned int sizeArrEl = sizeof(arr[0]);

    int size = sizeArr / sizeArrEl;
    printf("size = %ld / %ld = %d\tshort int\n", sizeArr, sizeArrEl, size);
}

void integer() {
    int arr[] = {90, 1, 15, 7, 11, 44, 65, 25};
    long unsigned int sizeArr = sizeof(arr);
    long unsigned int sizeArrEl = sizeof(arr[0]);

    int size = sizeArr / sizeArrEl;
    printf("size = %ld / %ld = %d\tint\n", sizeArr, sizeArrEl, size);
}

void long_integer() {
    long int arr[] = {90, 1, 15, 7, 11, 44, 65, 25};
    long unsigned int sizeArr = sizeof(arr);
    long unsigned int sizeArrEl = sizeof(arr[0]);

    int size = sizeArr / sizeArrEl;
    printf("size = %ld / %ld = %d\tlong int\n", sizeArr, sizeArrEl, size);
}

int main() {
    short_integer();
    integer();
    long_integer();
}

// cd data-types/array-dimensions
// gcc -o numerical-array numerical-array.c && ./numerical-array