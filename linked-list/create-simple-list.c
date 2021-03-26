#include <stdio.h>
#include <stdlib.h>
#include "globals.h"

void showList(simple_list);
void showListRecurvise(simple_list);
simple_list insertInTheHead(simple_list, int);

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

    return 0;
}

void showList(simple_list myL) {
    printf("\nShow List:\n");

    while (myL != NULL) {
        printf("%d\n", myL->value);
        myL = myL->next;
    }
}

void showListRecurvise(simple_list myL) {
    if( myL != NULL) {
        printf("%d\n", myL->value);
        showListRecurvise(myL -> next);
    }
}

simple_list insertInTheHead(simple_list myL, int i) {
    simple_list tmp;

    // allocate tmp in HEAP memory 
    tmp = (simple_list) malloc(sizeof(item));
        
    // assign 'i' ('input') to 'value' in the struct element pointed by 'tmp'
    tmp->value = i;

    // assign the next node to 'root' in the struct element pointed by 'tmp'
    tmp->next = myL;

    return tmp;
}

// cd linked-list
// gcc -o main create-simple-list.c && ./main