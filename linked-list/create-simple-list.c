#include <stdio.h>
#include <stdlib.h>
#include "globals.h"

int main() {
    // 'simple_list' is a pointer to 'item' struct
    simple_list root = NULL;    
    simple_list L;
    int input;

    printf("\tSimple Linked List\n\npress 0 to exit\n\n");

    do {
        // input
        printf("~ Insert a value: ");
        scanf("%d", &input);

        /* adding the element to the list */
        // '->' access a struct's field referenced by a pointer
        
        // allocate L in HEAP memory 
        L = (simple_list) malloc(sizeof(item));
        
        // assign 'input' to 'value' in the struct element pointed by 'L'
        L -> value = input;

        // assign the next node to 'root' in the struct element pointed by 'L'
        L -> next = root;

        // let 'root' points to the last element of the linked list
        root = L;


    } while( input != 0);

    // print out the linked list

    printf("\nThe values are:\n");

    L = root;
    while (L != NULL) {
        printf("%d\n", L->value);
        L = L->next;
    }

    // printf("\n");

    return 0;
}

// cd linked-list
// gcc -o main create-simple-list.c && ./main