#include <stdio.h>
#include <stdlib.h>
#include "globals.h"

int searchIterative(simple_list myL, int i) {
    int found = 0;

    while ((myL != NULL) && !found) {
        if(myL->value == i) {
            found = 1;
        } else {
            myL = myL->next;
        }
    }

    return found;
}

int searchRecursive(simple_list myL, int i) {
    if (myL != NULL) {
        if(myL->value == i) {
            return 1;
        } else {
            searchRecursive(myL->next, i);
        }
    } else {
        return 0;
    } 
}