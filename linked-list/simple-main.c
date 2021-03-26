#include <stdio.h>
#include <stdlib.h>

#include "globals.h"
#include "simple-create.h"
#include "simple-search.h"

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
        
        // let 'root' points to the last element of the linked list
        root = insertInTheHead(root, input);
    } while( input != 0);

    // print out the linked list
    showList(root);

    printf("\nShow List Recursive:\n");
    showListRecurvise(root);

    // search element
    printf("\nElement to find: ");
    scanf("%d", &input);

    // TODO create a function that takes in a search function
    if(searchIterative(root, input)) {
        printf("%d is inside the list.\n", input);
    } else {
        printf("%d is not inside the list.\n", input);
    }

    // search element - recursive
    printf("\nElement to find: ");
    scanf("%d", &input);

    if(searchRecursive(root, input)) {
        printf("%d is inside the list.\n", input);
    } else {
        printf("%d is not inside the list.\n", input);
    }

    return 0;
}

// cd linked-list
// gcc -o main simple-main.c simple-create.c simple-search.c && ./main