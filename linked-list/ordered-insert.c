#include <stdio.h>
#include <stdlib.h>
#include "globals.h"

simple_list orderedInsertIterative(simple_list myL, int i) {
    simple_list pprec, patt = myL, aux;

    int found = 0;

    while ((patt != NULL) && !found) {
        if (i  <= patt->value) {
            found = 1;
        } else {
            pprec = patt;
            patt = patt->next;
        }
    }

    aux = (simple_list) malloc(sizeof(item));
    aux->value = i;
    aux->next = patt;
    
    if(patt == myL) {
        return aux;
    } else {
        // list start
        pprec->next = aux;
        return myL;
    }
}