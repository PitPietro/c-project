# Binary Tree

## Table of content
- [1. Introduction](#1-introduction)
- [2. m-ary Tree](#2-m-ary-tree)
  - [2.1. Definitions](#21-definitions)
- [3. ADT Binary Tree](#3-adt-binary-tree)

## 1. Introduction
The list is a sequential data structure. Operations over list implies sequential access and sequential elaboration time. In the worst case, the complessity is **O(N)**, which means a lot of time for big list structures.
To overcome the timing issues, you need to implement a linked data structure, which is useful to manage large amount of data.

## 2. M-ary Tree
Trees are the most used not sequential data structure.
Data is stored into **nodes**. Hierarchical relationships are defined by
**arcs**, which connect the nodes.

A [tree](https://en.wikipedia.org/wiki/Tree_(graph_theory)) is a [DAG](https://en.wikipedia.org/wiki/Directed_acyclic_graph) (Directed Acyclic Graph) such that:
1. exists a node called **root** which has degree of entry equal to zero (a node without a parent)
2. each other node has degree of entry equal to one

### 2.1. Definitions
- **leaves**: nodes with degree of exit equal to `0`
- **node level**: the length of the path from the root to the given node 
- **tree height**: the length of the longest path from the root to a leaf
- if an **arc** connects node `A` to node `B`, node `A` is called the **parent node** of `B`, which is called a **child node** (or direct descendant) of `A`

Since, in a tree, the degree of entry of each node is known beforehand, instead of **degree of exit** you can simply call it **degree**.

Consequently:
- there is exactly one path from root to any another nodes.
- except the root, all nodes have exactly one parent
- a father can have zero or more children
- among the children of a node there is an order that distinguishes the first node, the second node, etc (usually drawn from left to right).

## 3. ADT Binary Tree
The **binary tree** is the simplest case of **tree**.
It can be empty or can have an element (at the `head`, in the so called "root node"). It has at most two child *subtrees*: `left` and `right`.

```c
typedef char element;
typedef enum {FALSE, TRUE} boolean;

typedef struct node {
    element value;
    struct node * left;
    struct node * right;
} NODE;

typedef NODE * tree;

tree root = NULL;
```

Trees as **recursive** structures:
- excluding the root node, in a binary tree the nodes can be
divided into two disjoint sets
- each of these subsets includes a child of the root node
plus all (and only) his descendants
- each of these subsets identifies a sub-tree

### 3.1. Examples
See the [binary-tree/examples](../data-types/adt/tree/binary-tree/examples/) folder: `data-types/adt/tree/binary-tree/examples`

## 4 Algorithms over Binary Trees

### 4.1. Tree Traversal
Traversal is a process to visit all the nodes of a tree (and print their values too). Since all nodes are connected via edges (links), you always start from the root (head) node: you can not random access a node in a tree.
There are three ways which you can traverse a tree:
- Inorder Traversal (for binary trees only)
  1. the left sub-tree
  2. the **root**
  3. the right sub-tree
- Preorder Traversal
  1. the **root**
  2. all the sub-trees from left to right
- Postorder Traversal
  1. all the sub-trees from left to right
  2. the **root**

```c
void inorder_traversal(tree t) {
  if (t != NULL) {

    // 1. left sub-tree
    inorder_traversal(t->left);
  
    // 2. print the root
    printf("%d", t->value);

    // 3. right sub-tree
    inorder_traversal(t->right);
  }
}

```c
void preorder_traversal(tree t) {
  if (t != NULL) {
  
    // this line can be even more generic, with a printElement() function
    // 1. print the root
    printf("%d", t->value);

    // 2. all the sub-trees from left to right
    preorder_traversal(t->left);
    preorder_traversal(t->right);
  }
}

```

```c
void postorder_traversal(tree t) {
  if (t != NULL) {

    // 1. all the sub-trees from left to right
    postorder_traversal(t->left);
    postorder_traversal(t->right);
  
    // 2. print the root
    printf("%d", t->value);
  }
}

```

TODO impelement with code functions in the example folder!
