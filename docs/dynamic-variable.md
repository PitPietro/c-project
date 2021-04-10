# Dynamic Variable

## Table of contents
- [1. Types of variables in C](#1-types-of-variables-in-c)
  - [1.1. Global variables](#11-global-variables)
  - [1.2. Automatic variables](#12-automatic-variables)
  - [1.3. Dynamic variables](#13-dynamic-variables)
- [2. Memory Allocation](#2-memory-allocation)
- [3. Memory Deallocation](#3-memory-deallocation)
  - [3.1. Dangling Reference](#31-dangling-reference)
  - [3.2 Unused Areas](#32-unused-areas)
- [4. Dynamic Array](#4-dynamic-array)
  - [4.1. Code examples](#41-code-examples)


## 1. Types of variables in C

### 1.1. Global variables
The **global** variables have the same *lifetime* of the entire program. Even the **static** variables have the same *lifetime* of the entire program, but thier *scope* is inside the function where they're defined.

### 1.2. Automatic variables
The automatic variables are:
- local variables
- formal parameters

They're *allocated* and *deallocated* automatically.

### 1.3. Dynamic variables
Data structure like lists or trees are dynamic.

Inside `<stdlib.h>` are defined the functions for:
- allocation: `malloc()`
- deallocation: `free()`

The can be refered only by using pointers.
Their *lifetime* is decided by the programmer who write the program.

## 2. Memory Allocation

```c
void * malloc(size_t dim)
```

The word `malloc` stands for MemoryALLOCation.

It asks the OS to allocate a memory area of `dim` bytes (from `HEAP`) and returns the address of the allocated memory or `NULL` in case of error.
**Please Note**: Be sure to always check for `malloc` not to return `NULL` during the program execution.

Since `malloc` returns a `void` pointer, you'll have to make an explicit cast to perform the assignment.

## 3. Memory Deallocation

```c
void free(void * p)
```

The allocated memory must be explicitly deallocated with the `free` function, which takes in only the pointer.

```c
int *p = (int *) malloc(sizeof(int));

// make stuff with the variable p

free(p);
```

It's not necessary to tell the dimension of the variable to deallocate: the OS already knows it thanks to the prevous `malloc` call.

If the memory is not correctly deallocated, you'll gen a **memory leaking** error.

In the case of *shared data structures*, it is necessary to know who is using a certain structure, in order to deallocate it only when there are no more references to it.

### 3.1. Dangling Reference
It occurs when, at some point of the program exection, there are pointers which points to a memory area that has been deallocated.

### 3.2 Unused Areas
The following example shows who is possible to lose the reference of allocated memory areas.

```c
int *p, *q;

p = (int *) malloc(sizeof(int));
q = (int *) malloc(sizeof(int));

*p = 50;
*q = 70;

// the solution goes here

q = p;

```

The HEAP memory which contains the number `70` is allocated but no more referenced. The solution is very easy:

```c
free(q);

```

## 4. Dynamic Array
The dimension of a dynamic array is decided during the allocation but, once allocated, it's not possible to be modified.

```c
int dim = 5;
int *p = (int *) malloc(dim * sizeof(int));
```

`p` points to `dim` adjacent cells (which can contains `int` values). `p` is a dynamic array.

The allocated area is accessile by:
- pointer notation: `*p`
- array notation: `p[]`

Assuming `*p` to store the numbers `24`, `55`, `0`, `8`, `76`.
```c
p[0] = 24
*(p) = 24

p[1] = 55
*(p + 1) = 55

// and so on
```


### 4.1. Code examples

```c
// array of dimension given by the user
// the array is filled by element of type 'long'

#include <stdio.h>
#include <stdlib.h>

int main() {
  int dim;
  long *l;
  
  scanf("%d", &dim);

  l = (long *) malloc(dim * sizeof(long));

  // use the array

  free(l);
  // l = NULL

  return 0;
}
```

Given an integer `n`, write a function which allocates and returns a string of dimension `n`.
```c
// allocate a string of given length
char * allocate(int dim) {
  return (char *) malloc(dim * sizeof(char));
}

int main() {
  char *p;

  p = allocate(42);

  return 0;
}

/*
// WRONG version

char * allocate(int dim) {
  char word[dim];
  return word;
}
*/
```