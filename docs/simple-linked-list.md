# Simple Linked List

## Table of contents
- [1. Introduction](#1-introduction)
  - [1.1. Concept of List](#11-concept-of-list)
  - [1.2. Sequential & Linked List](#12-sequential-&-linked-list)

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

### 2.1. Create a simple list