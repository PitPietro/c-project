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
        printf("index = %d \t value = %d\n", i, arr[i]);
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
        // printf("powOfTen: %d -- (n / powOfTen): %d -- value: %d -- arr[%d] = %d\n", powOfTen, n / powOfTen, value, index, arr[index]);

        index++;
    }
}


// it's very very similar to the tail recursive version
void recursive_find_palindrome(int number[], int k, int index) {
    if(0 <= index && index <= k/2) {
        if(number[index] != number[k - index]) {
            printf("Not a palindrome!\n");
            exit(1);
        } else {
            recursive_find_palindrome(number, k, index+1);
        }        
    } else {
        printf("The number is palindrome\n");
    }
}

void iterative_find_palindrome(int number[], int k) {
    int i = 0;

    // you do not need to check the whole indexes: you can also check only the first half of numbers
    while(0 <= i && i <= k/2) {
        // printf("i: %d\tk: %d\tn[i] = %d = %d = n[k-i]\n", i, k, number[i], number[k-i]);
        
        if(number[i] != number[k - i]) {
            printf("Not a palindrome!\n");
            exit(1);
        }

        i++;
    }

    printf("The number is palindrome\n");
}

void tail_recursive_find_palindrome(int number[], int k, int index) {
    int i = index;

    // you do not need to check the whole indexes: you can also check only the first half of numbers
    if(0 <= i && i <= k/2) {
        // printf("i: %d\tk: %d\tn[i] = %d = %d = n[k-i]\n", i, k, number[i], number[k-i]);
        
        if(number[i] != number[k - i]) {
            printf("Not a palindrome!\n");
            exit(1);
        }

        tail_recursive_find_palindrome(number, k, i+1);
    } else {
        printf("The number is palindrome\n");
    }
}

int main() {
    int number = 1236321;
    int digits = count_digits(number);
    int array[digits];
    
    save_int_to_array(number, array);
    print_array(array, digits);

    short int choose = 0;

    do {
        printf("\n\n~~~ MENU ~~~\n1.\trecursive\n2\titerative\n3.\ttail recursive\n0.\tEXIT\n\n");
        printf("What type of algorithm you need? ");
        scanf("%hd", &choose);

        switch (choose) {

        case 0: {
            printf("\n0. EXIT\nBye bye...\n");
            break;
        }
        case 1: {
            printf("\n1. Recursive\n");
            recursive_find_palindrome(array, digits-1, 0);
            break;
        }

        case 2: {
            printf("\n2.\tIterative\n");
            iterative_find_palindrome(array, digits-1);
            break;
        }

        case 3: {
            printf("\n3. Tail Recursive\n");
            tail_recursive_find_palindrome(array, digits-1, 0);
            break;
        }
            
        default: {
            printf("You choose %hd, it's out of renge... retry!\n\n", choose);
            break;
        }
            
        }
    } while(choose != 0);
}

// cd recursion/math-es
// gcc -o find-palindrome find-palindrome.c -lm && ./find-palindrome