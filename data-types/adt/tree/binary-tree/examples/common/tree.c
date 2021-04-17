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

void inorder_traversal(tree t) {
  if (t != NULL) {

    // 1. left sub-tree
    inorder_traversal(t->left);
  
    // 2. print the root
    printElement(t->value);

    // 3. right sub-tree
    inorder_traversal(t->right);
  }
}

void preorder_traversal(tree t) {
  if (t != NULL) {
  
    // 1. print the root
    printElement(t->value);

    // 2. all the sub-trees from left to right
    preorder_traversal(t->left);
    preorder_traversal(t->right);
  }
}

void postorder_traversal(tree t) {
  if (t != NULL) {

    // 1. all the sub-trees from left to right
    postorder_traversal(t->left);
    postorder_traversal(t->right);
  
    // 2. print the root
    printElement(t->value);
  }
}

// cd data-types/adt/tree/binary-tree/examples/common