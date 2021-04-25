#include "element.h"

typedef struct node {
    element value;
    struct node * left;
    struct node * right;
} NODE;

typedef NODE * tree;

// de-allocate the memorty of the tree
void free_tree(tree);

// getter
boolean is_empty(tree);

element get_root_value(tree);
tree left_subtree(tree);
tree right_subtree(tree);

// setter
tree empty_tree();

// traversal algorithms
void inorder_traversal(tree);
void preorder_traversal(tree);
void postorder_traversal(tree);

// search
boolean search_element(element, tree);

// count the nodes
int count_nodes(tree);

// count how many times the given element is stored in the tree;
int count_element_occurrences(element, tree);

// height
int max_subtree(int, int);
int height_aux(tree);
int height(tree);

// insertion
tree insert_in_head(element, tree, tree);
tree iterative_insertion(element, tree);
tree recursive_insertion_v1(element, tree);
tree recursive_insertion_v2(element, tree);

// search
boolean iterative_search_v1(element, tree);
boolean iterative_search_v2(element, tree);
boolean recursive_search_v1(element, tree);

// cd data-types/adt/tree/binary-search-tree/examples/common