# ADT - Simple List

## Table of Contents
- [1. Introduction](#1-introduction)
  - [1.1. Code Structure](#11-code-structure)
  - [1.2. The Problem of Generalisation](#12-the-problem-of-generalisation)
- [2. ADT element](#2-adt-element)

## 1. Introduction

### 1.1. Code Structure
It's very important to subdivide the project into different files:
- `element.h`
- `list.h`
- `list.c`

```c
/* element.h */

// type definition
typedef int element;

// property of element
typedef enum {false, true } boolean;
```

```c
/* list.h */

#include "element.h"

// ADT
typedef struct list_element {
    element value;
    struct list_element *next;
} item;

typedef item *list;

// primitives
list cons(list, element);

// non-primitives
void showList(list);
boolean member(list, element);
```

```c
/* list.c */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// primitives
cons(list l, element e) {
    list t;
    t = (list) malloc(sizeof(item));
    t->value=e;
    t->next=l;
    return t;
}

void showList(list l) {
    printf("[");
    
    while (l != NULL) {
        // assuming that 'value' is of type 'int'
        printf("%d", l->value);
        
        l = l->next;

        if (l != NULL) {
            printf(" , ");
        } 
    }
    
    printf("]\n");
}
```

```c
/* main.c */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// the client
int main() {
    list L1 = NULL;
    element el;
    
    do {
        // assuming that 'value' is of type 'int'
        printf("\n insert a value: ");
        scanf("%d", &el);
        L1 = cons(el, L1);
    } while (el != 0); // arbitrary condition

    showList(L1);
}

// gcc -o main main.c list.c && ./main
```

### 1.2. The Problem of Generalisation
The functions written above operate on lists are still **dependent on the type of elements**. The functioning of the list cannot rely on the type of elements with which it's composed by.

The solution is to write a **generic ADT** which works with any type of elements. It implies the use of an **auxiliary ADT element** and the realization of the **list ADT** in term of element.

An ADT element must provide functions for:
1. verify order relationship between elements
2. verify equality between elements
3. read an element from the standard input
4. write an element to the standard output

## 2. ADT element
