#include <stdio.h>
#include <stdlib.h>
#include "sorting-utils.h"

void quick_sort_interface(int a[], int dim);
void quick_sort_recursive(int a[], int inizio, int fine);

void quick_sort_interface(int a[], int dim) {
    quick_sort_recursive(a, 0, dim -1);
}

void quick_sort_recursive(int a[], int inizio, int fine) {
    int i, j, iPivot;
    int pivot;
    
    if (inizio < fine) {
        i = inizio;
        j = fine;
        iPivot = fine;
        pivot = a[iPivot];
        
        /* trova la posizione delpivot */
        do {
            while (i < j && a[i] <= pivot)
                i++;
            
            while (j > i && a[j] >= pivot)
                j--;
            
            if (i < j)
                swap(&a[i], &a[j]);
        } while (i < j);
        
        /* determinati i due sottoinsiemi */
        /* posiziona il pivot */
        
        if (i != iPivot && a[i] != a[iPivot]) {
            swap(&a[i], &a[iPivot]);
            iPivot = i;
        }
        
        /* ricorsione sulle sottoparti, se necessario */
        if (inizio < iPivot -1)
            quick_sort_recursive(a, inizio, iPivot -1);
        
        if (iPivot + 1 < fine)
            quick_sort_recursive(a, iPivot + 1, fine);
    }
}

int main() {
    int arr[] = {89, 61, 33, 24, 15, 18, 11, 10}; 
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("\n Quick sort recursive:\n");
    printf("Unsorted array:\n");
    print_array(arr, n);
    printf("\n~~~~~\n");

    quick_sort_interface(arr, n);

    printf("~~~~~\n");
    printf("Sorted array:\n");
    print_array(arr, n);
    printf("\n");

    return 0;
}


// cd sorting-algorithms/
// gcc -o quick quick.c sorting-utils.c && ./quick