# ADT - Simple List

## Table of Contents
- [1. Introduction](#1-introduction)
  - [1.1. Code Structure](#11-code-structure)
  - [1.2. The Problem of Generalisation](#12-the-problem-of-generalisation)
- [2. ADT element](#2-adt-element)
  - [2.1. element.h](#21-elementh)
  - [2.2. element.c](#22-elementc)
  - [2.3. list.h](#23-listh)
  - [2.4. list.c](#24-listc)
  - [2.5. Delete an element](#25-delete-an-element)
  - [2.6. Merge ordered lists](#26-merge-ordered-lists)

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

// properties of element
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

### 2.1. element.h
The header file `element.h` must contain:
1. `element` type definition
2. properties of `element`

Since it contains a definition, the file must be protected from the problem of multiple inclusions.

```c
/* element.h */

#ifndef ELEMENT_H
#define ELEMENT_H
typedef int element;

typedef enum { false, true } boolean;
boolean isLess(element, element);
boolean isEqual(element, element);
element getElement(void);
void printElement(element);
#endif
```

### 2.2. element.c

```c
/* element.c */

#include <stdio.h>
#include "element.h"

boolean isEqual(element e1, element e2) {
    return (e1 == e2);
    /*
    if (e1 == e2) return true;
    else return false;
    */
}

boolean isLess(element e1, element e2) {
    return (e1 < e2);
}

element getElement(void) {
    element el;
    scanf("%d", &el);
    return el;
}

void printElement(element el) {
    printf("%d", el);
}

```

Now that you know how `element` behave, you need to modify `list.h` and `list.c` generalizing the operations.

### 2.3. list.h
```c
/* list.h */

#include "element.h"

#include "element.h"

typedef struct list_element {
    element value;
    struct list_element *next;
} item;

typedef item *list;

// primitives
list cons(list, element);

// non-primitives
void showList(list);
```

### 2.4. list.c

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
        
        // printf("%d", l->value);
        printElement(l->value);
        
        l = l->next;

        if (l != NULL) {
            printf(" , ");
        } 
    }
    
    printf("]\n");
}
```

### 2.5. Delete an element
Given an element (key, or integer or whatever you want), delete the first occurrence of the element from list:
1. find the node to delete: if it's at the head of the list, just update the root pointer
2. if it's not the one at the head of the list, modify the next field of the predecessor node
3. always release the memory occupied by the node to delete

If you do not find any element equal to the one to delete, the list does not change.

```c
/* list.c  */

// ...

list delete(element el, list L) {
    boolean found = false;
    list aux = L, prev = NULL;
    
    if (aux != NULL) {
        if ( isEqual(aux->value,el)) {
            L = aux->next;
            free(aux);
        }
    } else {
        while ((aux != NULL) && (!found)) {
            if (isEqual(aux->value,el)) {
                found = true;
            } else {
                prev = aux;
                aux = aux->next;
            }
        }
            
        if (aux != NULL) {
            prev->next = aux->next;
            free(aux);
        }
    }
    return L; 
}
```

### 2.6. Merge ordered lists
```c
/* list.c */

list mergeList(list L1, list L2) {
    list L3=NULL;
    
    while ( (L1 != NULL) && (L2 != NULL) ) {
        if ( isLess(L1->value, L2->value) ) {
            L3 = insertInTheTail(L3, L1->value);
            L1 = L1->next;
        } else {
            L3 = insertInTheTail(L3, L2->value);
            L2 = L2->next;
        }
    }

    while (L1 != NULL) {
        L3 = insertInTheTail(L3, L1->value);
        L1 = L1->next;
    }

    while (L2 != NULL) {
        L3 = insertInTheTail(L3, L2->value);
        L2 = L2->next;
    }
    
    return L3;
}
```