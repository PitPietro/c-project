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
    print_element(t->value);
    printf("\t");

    // 3. right sub-tree
    inorder_traversal(t->right);
  }
}

void preorder_traversal(tree t) {
  if (t != NULL) {
    // 1. print the root
    print_element(t->value);

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
    print_element(t->value);
  }
}

boolean search_element(element e, tree t) {
  if (t == NULL) {
    return false;
  } else {
    if (e == t->value) {
      return true;
    } else {
      return ( (search_element(e, t->left)) || (search_element(e, t->right)) );
    }
  }
}

int count_nodes(tree t) {
  if(t == NULL) {
    return 0;
  } else {
    return 1 + count_nodes(t->left) + count_nodes(t->right);
  }
}

int count_element_occurrences(element e, tree t) {
  if(t == NULL) {
    return 0;
  } else {
    if (e == t->value) {
      return 1 + count_element_occurrences(e, t->left) + count_element_occurrences(e, t->right);
    } else {
      return count_element_occurrences(e, t->left) + count_element_occurrences(e, t->right);
    }
  }
}

int max_subtree(int a, int b) {
  if(a > b) {
    return a;
  } else {
    return b;
  }
}

int height_aux(tree t) {
  if(t == NULL) {
    return 0;
  } else {
    return ( 1 + max(height_aux(t->left), height_aux(t->right)) );
  }
}

int height(tree t) {
  if(t == NULL) {
    return 0;
  } else {
    return ( max(height_aux(t->left), height_aux(t->right)) );
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
      if ( is_less_or_equal(e, t->value) ) {
        p = t;
        t = t->left;
      } else {
        p = t;
        t = t->right;
      }
    }
  }

  if ( is_less_or_equal(e, p->value) ) {
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
    if ( is_less_or_equal(e, t->value) ) {
      t->left = recursive_insertion_v1(e, t->left);
    } else {
      t->right = recursive_insertion_v1(e, t->right);
    }

    return t;
  }
}

tree recursive_insertion_v2(element e, tree t) {
  if (t == NULL) {
    return insert_in_head(e, NULL, NULL);
  } else {
    if ( is_less_or_equal(e, t->value) ) {
      return t->left = insert_in_head(t->value, recursive_insertion_v2(e, t->left), t->right);
    } else {
      return t->right = insert_in_head(t->value, t->left, recursive_insertion_v2(e, t->right));
    }
  }
}

// search

boolean iterative_search_v1(element e, tree t) {
  while (t != NULL) {
    if (is_equal(e, t->value)) {
      return true;
    } else {
      if (is_less(e, t->value)) {
        t = t->left;
      } else {
        t = t->right;
      }
    }
  }

  return false;
}

boolean iterative_search_v2(element e, tree t) {
  boolean found = false;
  while ((t != NULL) && (!found)) {
    if (is_equal(e, t->value)) {
      found = true;
    } else {
      if (is_less(e, t->value)) {
        t = t->left;
      } else {
        t = t->right;
      }
    }
  }

  return found;
}

boolean recursive_search_v1(element e, tree t) {
  if (t == NULL) {
    return false;
  } else {
    if (is_equal(e, t->value)) {
      return true;
    } else {
      if (is_less(e, t->value)) {
        return recursive_search_v1(e, t->left);
      } else {
        return recursive_search_v1(e, t->right);
      }
    }
  }
}

// cd data-types/adt/tree/binary-search-tree/examples/common