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

// count the nodes
int countNodes(tree);

// count how many times the given element is stored in the tree;
int countElementOccurrences(element, tree);

// height
int max(int, int);
int heightAux(tree);
int height(tree);

// cd data-types/adt/tree/binary-tree/examples/common