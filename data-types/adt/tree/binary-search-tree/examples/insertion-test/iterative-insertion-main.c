#include "../common/tree.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    tree t1 = NULL;

    t1 = insert_in_head(5, NULL, NULL);

    t1 = iterative_insertion(2, t1);
    t1 = iterative_insertion(7, t1);

    printf("\nInorder traversal: ");
    inorder_traversal(t1);

    printf("\n");

    return 0;
}

// cd data-types/adt/tree/binary-search-tree/examples/insertion-test
// gcc -o main iterative-insertion-main.c ../common/tree.c ../common/element.c && ./main