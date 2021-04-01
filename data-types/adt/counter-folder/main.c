#include <stdio.h>
#include "counter.h"

void printMenu();

int main() {
    int input;
    counter myCounter;

    reset(&myCounter);
    
    printf("\tADT ~ counter\n\n");

    do {
        printMenu();
        printf("\n\tChoose: ");
        scanf("%d", &input);

        switch (input) {
            case 0:
                printf("Bye bye!\n");
                break;
            
            case 1: {
                reset(&myCounter);
                printCounter(myCounter);
            }
            break;

            case 2: {
                increment(&myCounter);
                printCounter(myCounter);
            }
            break;
            
            case 3: {
                decrement(&myCounter);
                printCounter(myCounter);
            }
            break;
            
            case 4:
                printCounter(myCounter);
                break;
            
            default:
                printf("operation not allowed.\n");
                break;
        }
    } while (input != 0);
}

void printMenu() {
    printf("\n\nMenu\n\t0) EXIT\n\t1) Reset\n\t2) Increment\n\t3) Decrement\n\t4) Get status\n");
}

// cd data-types/adt/counter-folder
// gcc -o main main.c counter.c && ./main