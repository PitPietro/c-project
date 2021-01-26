#include <stdio.h>
#include <stdlib.h>

#define ROW 4
#define COLUMN 6

void print_matrix(int m[][COLUMN]) {
    int i, j;

    for(i = 0; i < ROW; i++) {
        for(j = 0; j < COLUMN; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

}

int main() {
    // matrix initialization
    int matrix[ROW][COLUMN] = {
        {10, 50, 20, 70, 30, 60},
        {11, 59, 23, 74, 31, 65},
        {19, 54, 27, 72, 36, 68},
        {14, 51, 28, 75, 33, 69}};

    print_matrix(matrix);    
    return 0;
}

// cd matrix
// gcc -o int-matrix int-matrix.c && ./int-matrix

/*
int a[4][6]

a[0][0]  a[0][1]  a[0][2]  a[0][3]  a[0][4]  a[0][5]
a[1][0]  a[1][1]  a[1][2]  a[1][3]  a[1][4]  a[1][5]
a[2][0]  a[2][1]  a[2][2]  a[2][3]  a[2][4]  a[2][5]
a[3][0]  a[3][1]  a[3][2]  a[3][3]  a[3][4]  a[3][5]
*/