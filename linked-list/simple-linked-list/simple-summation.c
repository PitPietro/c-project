#include <stdio.h>
#include <stdlib.h>
#include "globals.h"

// evaluates the sum of all the value in the list - iterative version
int sumListIterative(simple_list myL) {
    int result = 0;
    int dim = 0;

    while(myL != NULL) {
        result += myL->value;
        dim++;

        myL = myL->next;
    }

    return result;
}

// evaluates the sum of all the value in the list - recursive version
int sumListRecursive(simple_list myL) {
    if(myL == NULL) {
        return 0;
    } else {
        return myL->value + sumListRecursive(myL->next);
    }
}

