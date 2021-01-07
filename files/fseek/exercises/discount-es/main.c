#include <stdio.h>
#include "discount.h"

int main() {
    product products[MAX];
    product updatedP[MAX];
    int n;

    fake_insert_products(products);
    write_bin(products);
    n = read_bin(updatedP);

    printf("Before discount:\n");
    print_products(updatedP, n);

    apply_discount(updatedP);
    
    printf("\nAfter discount:\n");
    print_products(updatedP, n);
    
    return 0;
}

// cd files/fseek/exercises/discount-es
// gcc -o main main.c discount.c && ./main

/*
fseek(...) allow you to perform read and write operations without having to close
and open again the same file.
This example shows how to apply a discount of 20% to the price of products stored in
a .bin file without having to read them all and re-write after the the price change.
*/