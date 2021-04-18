#include "element.h"

typedef struct node {
    element value;
    struct node * left;
    struct node * right;
} NODE;

typedef NODE * tree;

tree insertInHead(element, tree, tree);

// traversal algorithms
void inorder_traversal(tree);
void preorder_traversal(tree);
void postorder_traversal(tree);

// search
boolean searchElement(element, tree);

// cd data-types/adt/tree/binary-tree/examples/common