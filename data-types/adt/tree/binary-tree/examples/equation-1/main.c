#include <stdio.h>
#include <stdlib.h>
#include "../common/tree.h"

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
    
    printf("\nInorder traversal\n");
    inorder_traversal(t1);

    printf("\nPreorder traversal\n");
    preorder_traversal(t1);

    printf("\nPostorder traversal\n");
    postorder_traversal(t1);

    printf("\n");

    printf("\nInsert an element to search: ");
    element myElement = getElement();

    // if searchElement(myElement, t1) == 1) { ... }
    // if searchElement(myElement, t1) == true) { ... }
    if (searchElement(myElement, t1)) {
        printElement(myElement);
        printf(" has been found!\n");
    } else {
        printElement(myElement);
        printf(" has NOT been found!\n");
    }

    return 0;
}

// cd data-types/adt/tree/binary-tree/examples/equation-1
// gcc -o main main.c ../common/tree.c ../common/element.c && ./main