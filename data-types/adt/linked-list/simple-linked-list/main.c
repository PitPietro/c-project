#include <stdio.h>
#include <stdlib.h>

#include "globals.h"
#include "insert.h"
#include "search.h"
#include "length.h"
#include "ordered-insert.h"
#include "summation.h"
#include "sublist.h"

int main() {
    // 'simple_list' is a pointer to 'item' struct
    simple_list L1 = NULL;

    // reversed list
    simple_list L2 = NULL;

    // iteratively ordered list 
    simple_list L3 = NULL;

    // recursively ordered list 
    simple_list L4 = NULL;
    int input;

    printf("\tSimple Linked List\n\npress 0 to exit\n\n");

    do {
        // input
        printf("~ Insert a value: ");
        scanf("%d", &input);

        /* adding the element to the list */
        // '->' access a struct's field referenced by a pointer
        
        // let 'L1' points to the last element of the linked list
        L1 = insertInTheHead(L1, input);
        L2 = insertInTheTail(L2, input);
        L3 = orderedInsertIterative(L3, input);
        L4 = orderedInsertRecursive(L4, input);
    } while( input != 0);

    // print out the linked list
    printf("\nShow List (iterative):\n");
    showListIterative(L1);

    /*
    printf("\nShow List Recursive:\n");
    showListRecurvise(L1);

    // print out the "reversed" linked list
    showList(L2);
    */

    printf("\nShow the Reversed List (recursive):\n");
    showListRecurvise(L2);

    printf("\nShow the Iteratively Ordered List (recursive):\n");
    showListRecurvise(L3);

    printf("\nShow the Recursively Ordered List (recursive):\n");
    showListRecurvise(L4);

    // search element
    printf("\nElement to find: ");
    scanf("%d", &input);

    /* search */
    searchMask(searchIterative, L1, input, "L1");
    searchMask(searchRecursive, L1, input, "L1");

    searchMask(searchIterative, L2, input, "L2");
    searchMask(searchRecursive, L2, input, "L2");

    searchMask(searchIterative, L3, input, "L3");
    searchMask(searchRecursive, L4, input, "L4");

    printf("\nThe list L1 length is %d (iterative)\n", lengthIterative(L1));
    printf("The list L1 length is %d (recursive)\n", lengthRecursive(L1));
    printf("\nThe list L2 length is %d (iterative)\n", lengthIterative(L2));
    printf("The list L2 length is %d (recursive)\n", lengthRecursive(L2));
    printf("\nThe list L3 length is %d (iterative)\n", lengthIterative(L3));
    printf("The list L3 length is %d (recursive)\n", lengthRecursive(L3));
    printf("\nThe list L4 length is %d (iterative)\n", lengthIterative(L4));
    printf("The list L4 length is %d (recursive)\n", lengthRecursive(L4));

    printf("\nSum of all elements of L1 is %d (iterative)\n", sumListIterative(L1));
    printf("Sum of all elements of L1 is %d (recursive)\n", sumListRecursive(L1));
    printf("\nSum of all elements of L2 is %d (iterative)\n", sumListIterative(L2));
    printf("Sum of all elements of L2 is %d (recursive)\n", sumListRecursive(L2));
    printf("\nSum of all elements of L3 is %d (iterative)\n", sumListIterative(L3));
    printf("Sum of all elements of L3 is %d (recursive)\n", sumListRecursive(L3));
    printf("\nSum of all elements of L4 is %d (iterative)\n", sumListIterative(L4));
    printf("Sum of all elements of L4 is %d (recursive)\n", sumListRecursive(L4));


    // sub-list
    printf("\nSublist ~ insert element to start from: ");
    scanf("%d", &input);

    simple_list kL1 = subListIterative(L2, input);

    printf("The sublist L1 from %d to %d is:\n", input, lengthIterative(L1));
    showListIterative(kL1);

    return 0;
}

// cd data-types/adt/linked-list/simple-linked-list
// gcc -o main main.c insert.c search.c length.c ordered-insert.c summation.c sublist.c && ./main