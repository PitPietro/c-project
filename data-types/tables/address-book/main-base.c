// global declarations
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "global-declarations.h"
#include "base-functions.h"


int main() {
    int choose, inserted, fine;

    addressBook R;
    
    // logical dimension: empty table
    inserted = 0;
    fine = 0;
    
    do {
        menu();
        printf("\nChoose: ");
		scanf("%d", &choose);
        
        switch(choose) {
            case 1: {
                inserted = insertAddressBook(R, inserted);
                break;
            }
            case 2: {
                inserted = deleteAddressBook(R, inserted);
                break;
            }
            case 3: {
                searchAddressBook(R, inserted);
                break;
            }
            case 4: {
                printAddressBook(R, inserted);
                break;
            }
            case 0: {
                printf("Exiting the program... bye bye!\n");
                fine = 1;
                break;
            }
            default:
                printf("Try again, you will be luckier!\n");
        }
    } while(!fine);
    
    return 0;
}

// cd data-types/tables/address-book
// gcc -o main main-base.c base-functions.c && ./main