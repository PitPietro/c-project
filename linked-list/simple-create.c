#include <stdio.h>
#include <stdlib.h>
#include "globals.h"

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