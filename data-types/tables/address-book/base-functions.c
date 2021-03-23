#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global-declarations.h"

void menu(void) {
    printf("\nChoose what you want to do:\n");
    printf("  1) ~~ Insertion\n");
    printf("  2) ~~ Deletion\n");
    printf("  3) ~~ Search\n");
    printf("  4) ~~ Print Elements\n");
    printf("  0) ~~ Exit\n");
}

/*
 * return the number of elements inserted in the R vector
 * if the address book is not full, return 'dim + 1'
 * else, the function returns 'dim'
*/
int insertAddressBook(addressBook R, int dim) {
    if (dim <= N-1) {
        printf("\ninsert the name: ");
        scanf("%s", R[dim].firstName);
        printf("insert the number: ");
        scanf("%s", R[dim].phoneNumber);
        dim++;
    }
    else
        printf("the address book is full!\n");
    return dim;
}

int findAddressBook(addressBook R, int dim, element e) {
    int i,trovato=0;
    
    for (i = 0; i < dim && !trovato; i++)
    	if (!strcmp(e.firstName, R[i].firstName))
    		trovato = 1;
    
    if (trovato)
        return i - 1;
    else
        return N;
}

int deleteAddressBook(addressBook R, int dim) {
    int k, j;
    element e;
    
    printf("\nInsert name: ");
    scanf("%s",e.firstName);
    
    k = findAddressBook(R, dim, e);

    if (k < N) {
        printf("\n%s has been deleted\n", R[k].firstName);
    	for (j=k; j<dim-1; j++) R[j]=R[j+1];
    		dim--;
    } else
        printf("\n%s\t do not found\n", e.firstName);
    
    return dim;
}

void searchAddressBook(addressBook R, int dim) {
    int k;
    element e;
    
    printf("\nInsert name: ");
    scanf("%s",e.firstName);
    
    k = findAddressBook(R, dim, e);
    
    if (k < N) {
        printf("\nthe phone number of %s ", R[k].firstName);
    	printf("is %s \n", R[k].phoneNumber);
    } else
        printf("\n%s\t not found\n", e.firstName);
}

void printAddressBook(addressBook R, int dim) {
    if(dim == 0) {
        printf("\nThere are no numbers in your address book.\n");
        return;
    }

    int i;
    printf("The numbers in the addressBook are:\n");
    for(i = 0; i < dim; i++) {
        printf("%d)\t%s %s\t%s\n", i+1, R[i].lastName, R[i].firstName, R[i].phoneNumber);
    }
}