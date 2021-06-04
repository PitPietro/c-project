#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void menu(void);

int main() {
    int choose;
    list root = NULL;
    
    do {
        menu();
        printf("\nChoose: ");
		scanf("%d", &choose);
        
        switch(choose) {
            case 1: {
                root = insertAddressBook(root);
                break;
            }
            case 2: {
                root = deleteAddressBook(root);
                break;
            }
            case 3: {
                searchAddressBook(root);
                break;
            }
            /*
            case 4: {
                printAddressBook();
                break;
            } */
            case 0: {
                printf("Exiting the program... bye bye!\n");
                break;
            }
            default:
                printf("Try again, you will be luckier!\n");
        }
    } while(choose != 0);
    
    return 0;
}

void menu(void) {
    printf("\nChoose what you want to do:\n");
    printf("  1) ~~ Insertion\n");
    printf("  2) ~~ Deletion\n");
    printf("  3) ~~ Search\n");
    // printf("  4) ~~ Print Elements\n");
    printf("  0) ~~ Exit\n");
}

// cd data-types/adt/linked-list/list-of-struct/address-book/
// gcc -o main main.c list.c && ./main