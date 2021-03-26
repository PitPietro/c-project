#include <stdio.h>
#include <stdlib.h>

#include "globals.h"
#include "simple-insert.h"
#include "simple-search.h"
#include "simple-length.h"

int main() {
    // 'simple_list' is a pointer to 'item' struct
    simple_list root = NULL, L2 = NULL;    
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
        L2 = insertInTheTail(L2, input);
    } while( input != 0);

    // print out the linked list
    showList(root);

    printf("\nShow List Recursive:\n");
    showListRecurvise(root);

    // print out the "reversed" linked list
    showList(L2);

    printf("\nShow the Reversed List Recursive:\n");
    showListRecurvise(L2);

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

    printf("\nThe list length is %d (iterative)\n", lengthIterative(root));
    printf("The list length is %d (recursive)\n", lengthRecursive(root));

    return 0;
}

// cd linked-list
// gcc -o main simple-main.c simple-insert.c simple-search.c simple-length.c && ./main