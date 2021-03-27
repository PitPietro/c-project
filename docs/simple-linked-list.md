# Simple Linked List

## Table of contents
- [1. Introduction](#1-introduction)
  - [1.1. Concept of List](#11-concept-of-list)
  - [1.2. Sequential & Linked List](#12-sequential--linked-list)
- [2. Operations over a List](#2-operations-over-a-list)
  - [2.1. Add an element on the head or in the tail of a simple list](#21-add-an-element-on-the-head-or-in-the-tail-of-a-simple-list)
  - [2.2. Search an element](#22-search-an-element)
  - [2.3. Length of a list](#23-length-of-a-list)
- [3. Ordered List](#3-ordered-list)
  - [3.1. Iterative insertion](#31-iterative-insertion)


## 1. Introduction

### 1.1. Concept of List
A simple list is a sequnce of elements of the same data type. Just like all ADTs, the list is defined in terms of:
1. **domain** of the elements of the list
2. **construction** and **selection** operations
3. **predicates**

### 1.2. Sequential & Linked List
The **sequential list** is represented with an array: the list elements are allocated in adjacent locations.\
The **linked list**'s elements are associated with the address of the successive element's position (a pointer).\
The list element is called **node**, the index is called **arc**.

### Implementation with Pointers
In the list implementation with pointers, each list node is a structure made up by two fields:
1. element's value
2. successive node's position: a pointer (`NULL` if is the last element)

```c
// linked-list/globals.h

typedef struct linked_list {
    int value;
    struct linked_list *next;
} item;

typedef item *list;

list root = NULL;
```

## 2. Operations over a List
Take a look at the [`linked-list`](https://github.com/PitPietro/c-project/blob/main/linked-list/) folder.

The files common to all the operations are: 
- [globals.h](https://github.com/PitPietro/c-project/blob/main/linked-list/globals.h)
- [simple-main.c](https://github.com/PitPietro/c-project/blob/main/linked-list/simple-main.c)

### 2.1. Add an element on the head or in the tail of a simple list
- [simple-insert.h](https://github.com/PitPietro/c-project/blob/main/linked-list/simple-insert.h)
- [simple-insert.c](https://github.com/PitPietro/c-project/blob/main/linked-list/simple-insert.c)

### 2.2. Search an element
Since there's no index to increment (you're not dealing with an array), you need a pointer with which you can sequentially (or recursively) scan the list:
- [simple-search.h](https://github.com/PitPietro/c-project/blob/main/linked-list/simple-search.h)
- [simple-search.c](https://github.com/PitPietro/c-project/blob/main/linked-list/simple-search.c)

### 2.3. Length of a list
- [simple-length.h](https://github.com/PitPietro/c-project/blob/main/linked-list/simple-length.h)
- [simple-length.c](https://github.com/PitPietro/c-project/blob/main/linked-list/simple-length.c)

## 3. Ordered List
An order relationship must be defined on the base-domain of the elements of the list.\
The ordered insertion in the list can be:
- Iterative:
  scans the list with two auxiliary pointers, up to point where the element is to be inserted, and adds a node arranging the pointers
- Recurisive:
  1. without duplication
  2. duplicating a part of the list

The files are the same for both iterative and recursive ways:
- [ordered-insert.h](https://github.com/PitPietro/c-project/blob/main/linked-list/ordered-insert.h)
- [ordered-insert.c](https://github.com/PitPietro/c-project/blob/main/linked-list/ordered-insert.c)

### 3.1. Iterative insertion
How the algorithm works:
- scan the list until it reaches a node storing an element which is major than the one to insert
- allocate a new node with the element to insert
- connect the new node to the two adjacent ones

### 3.2. Recursive insertion
To insert an element, in an ordered way, in an ordered list:
- if the list is empty
  build a new list containing the new item
- otherwise, if the element to be inserted is less than the head of the list
  add the new item at the top of the given list,
- otherwise
  the element will be inserted later in the given list

The first two cases are elementary operations while the third case can be treated iteratively or going back to the same problem recursively, but on a simpler case:  it will be possible make either an insertion in the head or go back to the empty list
