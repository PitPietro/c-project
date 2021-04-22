#include "../common/tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

tree default_insertion(tree);

int main() {
    tree t1 = NULL;

    t1 = insert_in_head(5, NULL, NULL);
    t1 = default_insertion(t1);
    
    printf("inorder traversal: ");
    inorder_traversal(t1);

    printf("\n");

    // get random number from 1 to 20
    time_t t;
    srand( (unsigned) time(&t));
    int randomInt = (rand() % 20 ) + 1;

    element randomElement = (element) randomInt;

    boolean find = iterative_search_v1(randomElement, t1);

    if (find) {
        print_element(randomElement);
        printf(" has been found!\n");
    } else {
        print_element(randomElement);
        printf(" has not been found!\n");
    }

    find = iterative_search_v2(randomElement, t1);

    if (find) {
        print_element(randomElement);
        printf(" has been found!\n");
    } else {
        print_element(randomElement);
        printf(" has not been found!\n");
    }

    return 0;
}

tree default_insertion(tree root) {
    root = recursive_insertion_v1(1, root);
    root = recursive_insertion_v1(2, root);
    root = recursive_insertion_v1(3, root);
    root = recursive_insertion_v1(4, root);
    root = recursive_insertion_v1(6, root);
    root = recursive_insertion_v1(7, root);
    root = recursive_insertion_v1(8, root);
    root = recursive_insertion_v1(9, root);
    root = recursive_insertion_v1(10, root);
    return root;
}

// cd data-types/adt/tree/binary-search-tree/examples/search-test
// gcc -o main iterative-search-main.c ../common/tree.c ../common/element.c && ./main