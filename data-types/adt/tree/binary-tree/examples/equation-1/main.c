#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// a + (b * c - d) / e
int main() {
    tree t1 = NULL, t2 = NULL;
    t1 = insertInHead('b', NULL, NULL);
    t2 = insertInHead('c', NULL, NULL);

    t1 = insertInHead('*', t1, t2);
    t2 = insertInHead('d', NULL, NULL);
    
    t1 = insertInHead('-', t1, t2);
    t2 = insertInHead('e', NULL, NULL);
    
    t2 = insertInHead('/', t1, t2);
    t1 = insertInHead('a', NULL, NULL);
    
    t1 = insertInHead('+', t1, t2);
    
    printf("\nprint the tree \n");
    showTree(t1);
    printf("\n");

    return 0;
}

// cd data-types/adt/tree/binary-tree/examples/equation-1
// gcc -o main main.c tree.c && ./main