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

More definitions [here](https://data-flair.training/blogs/binary-tree-in-c/).

Since, in a tree, the degree of entry of each node is known beforehand, instead of **degree of exit** you can simply call it **degree**.

Consequently:
- there is exactly one path from root to any another nodes.
- except the root, all nodes have exactly one parent
- a father can have zero or more children
- among the children of a node there is an order that distinguishes the first node, the second node, etc (usually drawn from left to right).

### 2.2. ADT Binary Tree
The **binary tree** is the simplest case of **tree**.
It can be empty or can have an element (at the `head`, in the so called "root node"). It has at most two child *subtrees*: `left` and `right`.

#### 2.2.1. element.h
```c
/* element.h */

#ifndef ELEMENT_H
#define ELEMENT_H

typedef char element;
typedef enum {false, true} boolean;

boolean isLess(element, element);
boolean isEqual(element, element);
element getElement(void);
void printElement(element);

#endif
```

#### 2.2.2. element.c
```c
/* element.c */

#include "element.h"
#include <stdio.h>

boolean isEqual(element e1, element e2) {
    return (e1 == e2);
}

boolean isLess(element e1, element e2) {
    return (e1 < e2);
}

element getElement(void) {
    element el;
    scanf("%c", &el);
    return el;
}

void printElement(element el) {
    printf("%c\t", el);
}
```

#### 2.2.3. tree.h
```c
/* tree.h */

#include "element.h"

typedef struct node {
    element value;
    struct node * left;
    struct node * right;
} NODE;

typedef NODE * tree;

tree insertInHead(element, tree, tree);
```

#### 2.2.4. tree.c
```c
/* tree.c */

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
```

Trees as **recursive** structures:
- excluding the root node, in a binary tree the nodes can be
divided into two disjoint sets
- each of these subsets includes a child of the root node
plus all (and only) his descendants
- each of these subsets identifies a sub-tree

### 2.3. Examples
See the [binary-tree/examples](../data-types/adt/tree/binary-tree/examples/) folder: `data-types/adt/tree/binary-tree/examples`

## 3 Algorithms over Binary Trees

### 3.1. Tree Traversal
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

**Please Note**: Those algorithms' impelementation must be placed in `tree.c`, while the prototypes must be placed in `tree.h`.

### 3.2. Search an element
All the algorithms which operates over a tree are just *theme variation* of the **traversal algorithms**: they're the easiest way to visit all the nodes of a tree.
It only changes the operation to perform over the **root**.

```c
/* tree.c */

// ...

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
```

The usage is:
```c
tree t1 = NULL;

t1 = insertInHead(/* ... */);
// ...

printf("\nInsert an element to search: ");
element myElement = getElement();

if (searchElement(myElement, t1)) {
  printf("found!\n");
} else {
  printf("NOT found!\n");
}
```

### 3.3. Count node numbers
The algorithm, for a binary tree, works in this way: if the tree is empty, the nodes are `0`.
Else, the nodes are `1` (the **root**) `+` the left sub-tree's nodes `+` the right sub-tree's nodes.

```c
/* tree.c */

// ...

int countNodes(tree t) {
  if(t == NULL) {
    return 0;
  } else {
    return 1 + countNodes(t->left) + countNodes(t->right);
  }
}
```

The usage is:
```c
tree t1 = NULL;

t1 = insertInHead(/* ... */);
// ...

printf("\nThe nodes of the tree are: %d\n", countNodes(t1));
```

### 3.4. Count element occurrences
Count how many times the given element is stored in the tree.
Let's take the previous function and add a an `if` statement.

```c
/* tree.c */

// ...

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
```

The usage is:
```c
tree t1 = NULL;

t1 = insertInHead(/* ... */);
// ...

printf("\nInsert an element to search: ");
element myElement = getElement();

printf("\nThe element occurs %d times\n", countElementOccurrences(myElement, t1));
```

### 3.5. Height of the binary tree
If the tree is empty, the height is `0`. Else, the height is the maximum between the left subtree heigth and the right subtree heigth.

```c
tree t1 = NULL;

t1 = insertInHead(/* ... */);
// ...

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
```

The usage is:
```c
tree t1 = NULL;

t1 = insertInHead(/* ... */);
// ...

printf("\nThe tree height is: %d\n", height(t1));
```