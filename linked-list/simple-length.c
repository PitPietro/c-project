#include <stdio.h>
#include <stdlib.h>
#include "globals.h"

int lengthIterative(simple_list myL) {
    int dim = 0;

    while(myL != NULL) {
        dim++;
        myL = myL->next;
    }

    return dim;
}

int lengthRecursive(simple_list myL) {
    if(myL == NULL) {
        return 0;
    } else {
        return 1 + lengthRecursive(myL->next);
    }
}