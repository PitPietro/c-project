#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int count_digits(int n) {
    int count = 0;

    while(n != 0) {
        n /= 10;
        count++;
    }

    return count;
}

void print_array(int arr[], int dim) {
    int i;
    for(i = 0; i < dim; i++) {
        printf("index: %d \t value %d\n", i, arr[i]);
    }
}

void save_int_to_array(int n, int arr[]) {
    int index = 0; 
    if (0 == n) {
        exit(1);
    }
    
    unsigned int powOfTen = 0;
    powOfTen = pow(10, 1.0 + floor(log10(n)));

    while (powOfTen /= 10) {
        int value = (n / powOfTen) % 10;

        arr[index] = value;
        printf("powOfTen: %d -- (n / powOfTen): %d -- value: %d -- arr[%d] = %d\n", powOfTen, n / powOfTen, value, index, arr[index]);

        index++;
    }
}

int main() {
    int number = 12321;
    int digits = count_digits(number);
    int array[digits];
    
    save_int_to_array(number, array);
    print_array(array, digits);
}

// cd recursion/math-es
// gcc -o find-palindrome find-palindrome.c -lm && ./find-palindrome