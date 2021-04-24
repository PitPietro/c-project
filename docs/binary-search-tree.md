# Binary Search Trees

## Table of Content

## Introduction
The **BST** is a binary tree where the elemenets are positioned based on the relation they have with the **root** node's value.

The left subtree only stores values that are minor or equal to the root node's value.

The right subtree only stores values that are major than the root node's value.

By calling the `inorder_traversal()`function, you'll get the ordered list of elements (for example: `1, 3, 5, 7, 9, 12, 23`).

BST are usefull to:
- reduce the search complexity (if the tree is well-balanced)
- speed up insertion and deletion

### Non-balanced binary tree
If the tree is not balanced, it will look like a list: all the elemenets are stored in the right subtree and the left subtree is left empty or, viceversa, the elemenets are stored in the left subtree and the right subtree is left empty.

### Balanced binary tree
A tree whose elements are evenly distributed among the subtrees, is a **balanced tree**. Off course, there are algorithms for balancing non-balanced trees.
In the balanced BST, for each node, the height of the left and right subtrees differ al most for a unit.

#### Complete binary tree
In a balanced and complete binary tree, each node except the leaves, has exit degree equal to 2.
Given `h` the height of the tree, the number of nodes is `N = 2`<sup>`h+1`</sup>`- 1`

## Algorithms over BST
Operations that modify the tree must leave the sorting properties unchanged.

Between the values stored in the nodes's tree, there must be defined a **total order relationship**.

You need to use the `isEqual()` and `isLess()` functions previously defined in [`element.c`](../data-types/adt/tree/binary-search-tree/examples/common/element.c) file.

### Insertion
For the insertion, there are the following ways:
1. iterative
2. ricorsive
  - do not copying the structure
  - copying the structure


#### Iterative Insertion
Moves a pointer to the left (or to the right) until it reaches a leaf, then it connects the new node under that leaf: the insertion function iteratively updates a pointer, looking for the correct insertion position. Once it finds the node, it appends the new node as a left (or right) child, in order to keep the *sorting properties* unchanged.

```c
/* tree.c */

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

```

#### Recursive Insertion - v1
Given `t`, the pointer which identify the sub-tree where the element `e` must be inserted.
If `t` is `NULL`, the function returns a new **node** storing the element `e`. In this case, the function stops here.

If `t` is not `NULL` and if `e` is minor or equal than the element stored in the root of `t` (`t->value`), then insert a new node in the left sub-tree of `t`. This node have `value` equal to `e` and both the left and right nodes equal to `NULL`.  

Else, if `t` is not `NULL` and if `e` is major than the element stored in the root of `t` (`t->value`), then insert a new node in the right sub-tree of `t`. This node have `value` equal to `e` and both the left and right nodes equal to `NULL`.

```c
/* tree.c */

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

```

#### Recursive Insertion - v2
Rebuilds the tree afterwards, after having carried out the ordered insertion. This version take a lot of time.

```c
/* tree.c */

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

```

### Search
The number of comparisons that has to be made during a **search** is at most equal to the **height** of the tree.

For the insertion, there are the following ways:
1. iterative
2. ricorsive

#### Iterative Search
Given `t`, the pointer which identify a binary tree, assigned to the **root** of the tree and `e` the element to search.
While `t` is not `NULL` and its value is different from the element `e` that is searched:
- if `t->value` is equal to `e`, return `true`
- if `t->value` is minor than `e`, continue the search in the left sub-tree
- if `t->value` is major than `e`, continue the search in the right sub-tree

```c
/* tree.c */

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

```

#### Recursive Search
Given `t`, the pointer which identify a binary tree, assigned to the **root** of the tree and `e` the element to search.
If `t` is empty, return `false`, else:
- if `t->value` is equal to `e`, return `true`
- if `t->value` is minor than `e`, continue the search in the left sub-tree
- if `t->value` is major than `e`, continue the search in the right sub-tree

```c
/* tree.c */

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

```

#### Complexity of the search
A binary search tree reduces the complexity of the search algorithm: it excludes half a tree for each comparison.

The outcome of the comparison tells which side the searched element is on:
- in the left subtree, if the element is less than root
- in the right subtree, if the element is greater than the root

The number of comparisons is, in the worst case, proportional to the height of the tree. It's important to keep the tree balanced: all paths from root to leaves should have more or less the same height.

```c
/* tree.c */


```

### Binary Search
In case of a balanced BST, the search makes `H + 1` comparisons in the works case (where `H` is the height of the tree). At each step, excludes half a tree. This algorithm turns out to be a binary search because, to explore a space of **N** elements, it needs at most `H + 1` comparisons, which is equal to **O (log <sub>2</sub> N)** comparisons for balanced trees.

## AVL Tree