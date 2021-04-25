#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

void free_tree(tree t) {
  if (t != NULL) {
    free_tree(left_subtree(t));
    free_tree(right_subtree(t));
    free(t);
  } else {
    return; // if (is_empty(t))
  }
}

// getter

boolean is_empty(tree t) {
  // return (t == NULL)
  if (t == NULL) {
    return true;
  } else {
    return false;
  }
}

element get_root_value(tree t) {
  if(is_empty(t) == false) {
    return (t->value);
  }
}

tree left_subtree(tree t) {
  if (is_empty(t)) {
    return (NULL);
  } else {
    return (t->left);
  }
}

tree right_subtree(tree t) {
  if (is_empty(t)) {
    return (NULL);
  } else {
    return (t->right);
  }
}

// setter
tree empty_tree() {
  return NULL;
}

void inorder_traversal(tree t) {
  if (t != NULL) {
    // 1. left sub-tree
    inorder_traversal(left_subtree(t));
  
    // 2. print the root
    print_element(get_root_value(t));
    printf("\t");

    // 3. right sub-tree
    inorder_traversal(right_subtree(t));
  }
}

void preorder_traversal(tree t) {
  if (t != NULL) {
    // 1. print the root
    print_element(get_root_value(t));
    printf("\t");

    // 2. all the sub-trees from left to right
    preorder_traversal(left_subtree(t));
    preorder_traversal(right_subtree(t));
  }
}

void postorder_traversal(tree t) {
  if (t != NULL) {
    // 1. all the sub-trees from left to right
    postorder_traversal(left_subtree(t));
    postorder_traversal(right_subtree(t));
  
    // 2. print the root
    print_element(get_root_value(t));
    printf("\t");
  }
}

boolean search_element(element e, tree t) {
  if (is_empty(t)) {
    return false;
  } else {
    if (e == get_root_value(t)) {
      return true;
    } else {
      return ( (search_element(e, left_subtree(t))) || (search_element(e, right_subtree(t))) );
    }
  }
}

int count_nodes(tree t) {
  if(is_empty(t)) {
    return 0;
  } else {
    return 1 + count_nodes(left_subtree(t)) + count_nodes(right_subtree(t));
  }
}

int count_element_occurrences(element e, tree t) {
  if(is_empty(t)) {
    return 0;
  } else {
    if (e == get_root_value(t)) {
      return 1 + count_element_occurrences(e, left_subtree(t)) + count_element_occurrences(e, right_subtree(t));
    } else {
      return count_element_occurrences(e, left_subtree(t)) + count_element_occurrences(e, right_subtree(t));
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
  if(is_empty(t)) {
    return 0;
  } else {
    return ( 1 + max_subtree(height_aux(left_subtree(t)), height_aux(right_subtree(t))) );
  }
}

int height(tree t) {
  if(is_empty(t)) {
    return 0;
  } else {
    return ( max_subtree(height_aux(left_subtree(t)), height_aux(right_subtree(t))) );
  }
}

// insertion

tree insert_in_head(element el, tree leftTree, tree rightTree) {
  tree myTree;

  myTree = (NODE *) malloc(sizeof(NODE));
  myTree->value = el;
  myTree->left = leftTree;
  myTree->right = rightTree;

  return (myTree);
}

tree iterative_insertion(element e, tree root) {
  // p stands for predecessor
  tree p = NULL, t = root;

  if (is_empty(root)) {
    return insert_in_head(e, NULL, NULL);
  } else {
    while (t != NULL) {
      if ( is_less_or_equal(e, get_root_value(t)) ) {
        p = t;
        t = left_subtree(t);
      } else {
        p = t;
        t = right_subtree(t);
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
    if ( is_less_or_equal(e, get_root_value(t)) ) {
      t->left = recursive_insertion_v1(e, left_subtree(t));
    } else {
      t->right = recursive_insertion_v1(e, right_subtree(t));
    }

    return t;
  }
}

tree recursive_insertion_v2(element e, tree t) {
  if (is_empty(t)) {
    return insert_in_head(e, NULL, NULL);
  } else {
    if ( is_less_or_equal(e, get_root_value(t)) ) {
      return t->left = insert_in_head(get_root_value(t), recursive_insertion_v2(e, left_subtree(t)), right_subtree(t));
    } else {
      return t->right = insert_in_head(get_root_value(t), left_subtree(t), recursive_insertion_v2(e, right_subtree(t)));
    }
  }
}

// search

boolean iterative_search_v1(element e, tree t) {
  while (t != NULL) {
    if (is_equal(e, get_root_value(t))) {
      return true;
    } else {
      if (is_less(e, get_root_value(t))) {
        t = left_subtree(t);
      } else {
        t = right_subtree(t);
      }
    }
  }

  return false;
}

boolean iterative_search_v2(element e, tree t) {
  boolean found = false;
  while ((t != NULL) && (!found)) {
    if (is_equal(e, get_root_value(t))) {
      found = true;
    } else {
      if (is_less(e, get_root_value(t))) {
        t = left_subtree(t);
      } else {
        t = right_subtree(t);
      }
    }
  }

  return found;
}

boolean recursive_search_v1(element e, tree t) {
  if (is_empty(t)) {
    return false;
  } else {
    if (is_equal(e, get_root_value(t))) {
      return true;
    } else {
      if (is_less(e, get_root_value(t))) {
        return recursive_search_v1(e, left_subtree(t));
      } else {
        return recursive_search_v1(e, right_subtree(t));
      }
    }
  }
}

// cd data-types/adt/tree/binary-search-tree/examples/common