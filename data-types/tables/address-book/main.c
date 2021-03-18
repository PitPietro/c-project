// global declarations
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

typedef struct
{
	char name[20];
    char telefono[16];
} element;

typedef element addressBook[N];

// prototipi
void menu(void);
int insert(addressBook, int);
int delete(addressBook, int);
void search(addressBook, int);
int find(addressBook, int, element);

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
                inserted = insert(R, inserted);
                break;
            }
            case 2: {
                inserted = delete(R, inserted);
                break;
            }
            case 3: {
                search(R, inserted);
                break;
            }
            case 0: {
                printf("Bye bye!\n");
                fine = 1;
                break;
            }
            default:
                printf("Try again, you will be luckier!\n");
        }
    } while(!fine);
    
    return 0;
}

void menu(void) {
    printf("\nChoose what you want to do:\n");
    printf("\t1) ~~ Insertion\n");
    printf("\t2) ~~ Deletion\n");
    printf("\t3) ~~ Search\n");
    printf("\t0) ~~ Exit\n");
}

/*
 * return the number of elements inserted in the R vector
 * if the address book is not full, return 'dim + 1'
 * else, the function returns 'dim'
*/
int insert (addressBook R, int dim) {
    if (dim <= N-1) {
        printf("\ninsert the name: ");
        scanf("%s", R[dim].name);
        printf("insert the number: ");
        scanf("%s", R[dim].telefono);
        dim++;
    }
    else
        printf("the address book is full!\n");
    return dim;
}

int delete(addressBook R, int dim) {
    int k, j;
    element e;
    
    printf("\nInsert name: ");
    scanf("%s",e.name);
    
    k = find(R, dim, e);

    if (k < N) {
        printf("\n%s has been deleted\n", R[k].name);
    	for (j=k; j<dim-1; j++) R[j]=R[j+1];
    		dim--;
    } else
        printf("\n%s\t do not found\n", e.name);
    
    return dim;
}

int find(addressBook R, int dim, element e) {
    int i,trovato=0;
    
    for (i = 0; i < dim && !trovato; i++)
    	if (!strcmp(e.name, R[i].name))
    		trovato = 1;
    
    if (trovato)
        return i - 1;
    else
        return N;
}

void search(addressBook R, int dim) {
    int k;
    element e;
    
    printf("\nInsert name: ");
    scanf("%s",e.name);
    
    k = find(R, dim, e);
    
    if (k < N) {
        printf("\nthe phone number of %s ", R[k].name);
    	printf("is %s \n", R[k].telefono);
    } else
        printf("\n%s\t not found\n", e.name);
}

// cd data-types/tables/address-book
// gcc -o main main.c && ./main