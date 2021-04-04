#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/* insertion */

list insertInTheHead(list myL, element myE) {
    list tmp;

    // allocate tmp in HEAP memory 
    tmp = (list) malloc(sizeof(item));
    tmp->value = myE;
    tmp->next = myL;

    return tmp;
}

list orderedInsertRecursive(list myL, element myE) {
    if(myL == NULL) {
        return insertInTheHead(myL, myE);
    } else if(strcmp(myE.firstName, myL->value.firstName) <= 0) {
        return insertInTheHead(myL, myE);
    } else {
        myL->next = orderedInsertRecursive(myL->next, myE);
        return myL;
    }
}

list insertAddressBook(list myL) {
    element myE;

    printf("\nInsert the first name: ");
    scanf("%s", myE.lastName);

    printf("\nInsert the last name: ");
    scanf("%s", myE.lastName);

    printf("\nInsert the phone number: ");
    scanf("%s", myE.lastName);

    return orderedInsertRecursive(myL, myE);
}

/* deletion */

list delete(list myL, element myE) {
    int found = 0;
    list aux=myL, prev = NULL;
    
    if (aux != NULL) {
        if (strcmp(aux->value.firstName, myE.firstName) == 0) {
            printf("\n%s %s has been deleted\n", aux->value.firstName, aux->value.lastName);
            myL = aux->next;
            free(aux);
        }
    } else {
        while ((aux != NULL) && (!found)) {
            if (strcmp(aux->value.firstName, myE.firstName) == 0)
                found = 1;
            else {
                prev = aux;
                aux = aux->next;
            }
        }    
        if (aux != NULL) {
            printf("\n%s %s has been deleted\n", aux->value.firstName, aux->value.lastName);
            prev->next = aux->next;
            free(aux);
        }
    }
    
    return myL;
}

list deleteAddressBook(list myL) {
    element myE;

    printf("\nInsert the first name: ");
    scanf("%s", myE.lastName);

    printf("\nInsert the last name: ");
    scanf("%s", myE.lastName);

    return delete(myL, myE);
}

/* searching */

list find(element myE, list myL) {
    list L = myL;
    
    int found = 0;
    
    while ( (L != NULL) && (!found) ) {
        if( (!strcmp(myE.firstName, L->value.firstName)) && (!strcmp(myE.lastName, L->value.lastName)) ) {
            found = 1;
        } else {
            L = L->next;
        }
    }

    if (found)
        return L;
    else
        return NULL;
}

void searchAddressBook(list myL) {
    list k = NULL;

    element myE;
    printf("\nInsert the first name: ");
    scanf("%s", myE.firstName);

    printf("\nInsert the last name: ");
    scanf("%s", myE.lastName);

    k = find(myE, myL);

    if (k != NULL) {
        printf("\nThe phone number of %s %s is %s", k->value.firstName, k->value.lastName, k->value.phoneNumber);
    } else {
        printf("\n%s %s not found\n", myE.firstName, myE.lastName);
    }
}