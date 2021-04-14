typedef char element;
typedef enum {FALSE, TRUE} boolean;

typedef struct node {
    element value;
    struct node * left;
    struct node * right;
} NODE;

typedef NODE * tree;

tree insertInHead(element, tree, tree);
void showTree(tree);

// cd data-types/adt/tree/binary-tree/examples/equation-1