#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void menu(void);

list open_from_file(list);

int main() {
    printf("\nADT ~ List");

    char c;
    printf("\nLoad address book binary from file? (Y/n): ");
    scanf("%c", &c);

    list root;
    if ((c == 'Y') || (c == 'y')) {
        root = open_from_file(root);
    } else {
        root = NULL;
    }

    int choose;
    do {
        menu();
        printf("\nChoose: ");
        scanf("%d", &choose);

        switch (choose) {
            case 1: {
                root = insert_address_book(root);
                break;
            }
            case 2: {
                root = delete_address_book(root);
                break;
            }
            case 3: {
                search_address_book(root);
                break;
            }
            case 4: {
                print_address_book(root);
                break;
            }
            case 0: {
                printf("Exiting the program... bye bye!\n");
                break;
            }
            default:
                printf("Try again, you will be luckier!\n");
        }
    } while (choose != 0);

    return 0;
}

void menu(void) {
    printf("\nChoose what you want to do:\n");
    printf("  1) ~~ Insertion\n");
    printf("  2) ~~ Deletion\n");
    printf("  3) ~~ Search\n");
    printf("  4) ~~ Print Elements\n");
    printf("  0) ~~ Exit\n");
}

/**
 * Fill the list with the element stored in the .bin file
 * @param l list where to store elements
 * @return filled list
 */
list open_from_file(list l) {
    // declare local variables
    FILE *fp;
    char *fileName;
    element e;

    // let the user insert the filename (could add a check about .bin extension)
    printf("Insert file name: ");
    scanf("%s", fileName);

    // try to open the file
    if((fp = fopen(fileName, "rb")) == NULL) {
        printf("Error while opening %s\n", fileName);
        exit(1);
    }

    // perform reading operations
    while(fread(&e, sizeof(element), 1, fp) == 1) {
        // if the element is not a duplicate, insert it into the list
        if(find_element(l, e) == 0) {
            l = recursive_element_insertion(l, e);
        }
    }

    // try to close the file
    if(fclose(fp) != 0) {
        printf("Error: wrong file closure!\n");
        exit(2);
    }

    // return the filled list
    return l;
}

// cd data-types/adt/linked-list/list-of-struct/actions-over-files/address-book/
// gcc -o main main.c list.c element.c && ./main