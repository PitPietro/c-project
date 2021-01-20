#include <stdio.h>

void swap(int * x, int * y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void print_array(int numbers[], int size) {
    int i;
    
    for(i = 0; i < size; i++) {
        printf("%d\t", numbers[i]);
    }
}