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
