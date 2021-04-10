#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
/*
allow to pass any search algorithm which has the same arguments definition
*/
int searchMask(int (*anySearch)(simple_list myL, int i), simple_list L, int el, char listName[3]) {
    if( (*anySearch)(L, el) ) {
        printf("%d is inside the list %s.\n", el, listName);
    } else {
        printf("%d is not inside the list %s.\n", el, listName);
    }
}