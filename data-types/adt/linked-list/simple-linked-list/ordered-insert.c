#include <stdio.h>
#include <stdlib.h>

#include "globals.h"
#include "insert.h"

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

simple_list orderedInsertRecursive(simple_list myL, int i) {
    if(myL == NULL) {
        return insertInTheHead(myL, i);
    } else if(i <= myL->value) {
        return insertInTheHead(myL, i);
    } else {
        myL->next = orderedInsertRecursive(myL->next, i);
        return myL;
    }
}

/*
// this version will lead to Structure Copying so it won't be used

simple_list orderedInsertRecursiveV2(simple_list myL, int i) {
    if(myL == NULL) {
        return insertInTheHead(myL, i);
    } else if(i <= myL->value) {
        return insertInTheHead(myL, i);
    } else {
        return insertInTheHead(orderedInsertRecursive(myL->next, i), myL->value);
    }
}

*/