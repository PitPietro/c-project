#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

tree insertInHead(element el, tree leftTree, tree rightTree) {
    tree myTree;

    myTree = (NODE *) malloc(sizeof(NODE));
    myTree->value = el;
    myTree->left = leftTree;
    myTree->right = rightTree;

    return (myTree);
}

void showTree(tree myTree) {
    if(myTree != NULL) {
        printf("%c", myTree->value);

        showTree(myTree->left);
        showTree(myTree->right);
    }
}

// cd data-types/adt/tree/binary-tree/examples/equation-1