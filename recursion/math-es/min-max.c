#include <stdio.h>
#include <stdlib.h>

void max(int numbers[], int index, int * m) {
    if(index < 0) {
        return;
    } else {
        if(*m < numbers[index]) {
            *m = numbers[index];
        }

        printf("|  i = %d  |  n[%d] = %d\t|  m = %d  |\n", index, index, numbers[index], *m);

        max(numbers, index - 1, m);
    }
}

int main() {
    int arr[] = {90, 1, 15, 7, 11, 44, 65, 25};
    long unsigned int sizeArr = sizeof(arr);
    long unsigned int sizeArrEl = sizeof(arr[0]);

    int size = sizeArr / sizeArrEl;
    printf("size = %ld / %ld = %d\n", sizeArr, sizeArrEl, size);
    
    int M = arr[size-1];
    printf("Last element of the array is %d at index %d\n\n", M, size-1);

    max(arr, size-2, &M);
    printf("\n~ ~ L 0 a d 1 n g ~ ~\n\nmax = %d\n", M);
}

// cd recursion/math-es
// gcc -o min-max min-max.c && ./min-max