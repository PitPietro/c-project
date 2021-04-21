#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

tree insert_in_head(element el, tree leftTree, tree rightTree) {
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
    printf("\t");

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

boolean searchElement(element e, tree t) {
  if (t == NULL) {
    return false;
  } else {
    if (e == t->value) {
      return true;
    } else {
      return ( (searchElement(e, t->left)) || (searchElement(e, t->right)) );
    }
  }
}

int countNodes(tree t) {
  if(t == NULL) {
    return 0;
  } else {
    return 1 + countNodes(t->left) + countNodes(t->right);
  }
}

int countElementOccurrences(element e, tree t) {
  if(t == NULL) {
    return 0;
  } else {
    if (e == t->value) {
      return 1 + countElementOccurrences(e, t->left) + countElementOccurrences(e, t->right);
    } else {
      return countElementOccurrences(e, t->left) + countElementOccurrences(e, t->right);
    }
  }
}

int max(int a, int b) {
  if(a > b) {
    return a;
  } else {
    return b;
  }
}

int heightAux(tree t) {
  if(t == NULL) {
    return 0;
  } else {
    return ( 1 + max(heightAux(t->left), heightAux(t->right)) );
  }
}

int height(tree t) {
  if(t == NULL) {
    return 0;
  } else {
    return ( max(heightAux(t->left), heightAux(t->right)) );
  }
}

// insertion
tree iterative_insertion(element e, tree root) {
  // p stands for predecessor
  tree p = NULL, t = root;

  if (root == NULL) {
    return insert_in_head(e, NULL, NULL);
  } else {
    while (t != NULL) {
      if ( isLessOrEqual(e, t->value) ) {
        p = t;
        t = t->left;
      } else {
        p = t;
        t = t->right;
      }
    }
  }

  if ( isLessOrEqual(e, p->value) ) {
    p->left = insert_in_head(e, NULL, NULL);
  } else {
    p->right = insert_in_head(e, NULL, NULL);
  }

  return root;
}

tree recursive_insertion_v1(element e, tree t) {
  if (t == NULL) {
    return insert_in_head(e, NULL, NULL);
  } else {
    if ( isLessOrEqual(e, t->value) ) {
      t->left = recursive_insertion_v1(e, t->left);
    } else {
      t->right = recursive_insertion_v1(e, t->right);
    }

    return t;
  }
}

// cd data-types/adt/tree/binary-search-tree/examples/common