#include <stdio.h>
#include <stdlib.h>
#include "globals.h"
#include "simple-insert.h"

simple_list subListIterative(simple_list myL, int k) {
    simple_list tmpList = NULL;
    int dim = 0;

    while(myL != NULL) {
        if(k < dim) {
            tmpList = insertInTheTail(tmpList, myL->value);
        }

        dim++;
        myL = myL->next;
    }

    return tmpList;
}