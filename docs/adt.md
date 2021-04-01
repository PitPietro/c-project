# ADT

## Table of Contents
- [1. Software Components](#1-software-components)
  - [1.1. Libraries](#11-libraries)
  - [1.2. Data Abstraction](#12-data-abstraction)
  - [1.3. Abstract Data Type](#13-abstract-data-type)
- [2. ADT implementation in C](#2-adt-implementation-in-c)
  - [2.1. ADT realization](#21-adt-realization)
  - [2.2. ADT operations](#22-adt-operations)
  - [2.3. Limits of ADT in C](#23-limits-of-adt-in-c)
- [3. Examples](#3-examples)

## 1. Software Components
The software components of an ADT are:
1. libraries
2. data abstraction
3. abstract data type (ADT)

### 1.1. Libraries
The component:
- makes visible functions and procedures which do not use local variables
- is a collection of operations (and global constants)

A library can be:
1. system library: i.e. `#include <stdio.h>`
2. user-defined: i.e. `#include "my-library.h"`

### 1.2. Data Abstraction
The component has local data, which are hidden, and makes visible externally the prototypes of the invocable operations on these local data, but not the data identifiers.
Through one of these operations, it possible to assign an initial value to the hidden local data.

### 1.3. Abstract Data Type
The component exports:
1. identifier of type **T**
2. prototypes of the operations that can be performed on data which have been declared of this type **T**

The *customers* of the component (i.e. `main.c` or other callers) declare, and therefore control, the *lifetime* of variables of type T.

An ADT defines a conceptual category with its properties:
- type definition (which implies a domain **D**)
- set of admissible operations on objects of that type
  1. functions
  2. predicates

## 2. ADT implementation in C
In C programming language an ADT is made by:
- a new type defined with `typedef`
- a function foreach operation (i.e. create, read, update, delete, add, ...)

### 2.1. ADT realization

An ADT is realized splitting up interface and implementation info the following files:
```c
/* filename.h */

typedef [type] [name];
// i.e. typedef int counter;

// functions declaration

/* i.e.
void reset(counter *);
void increment(counter *);
*/
```

```c
/* filename.c */

#include "filename.h"

// functions definition

/* i.e.
void reset(counter C*) {
    *C = 0;
}

void increment(counter C*) {
    (*C)++;
}
*/
```

The client can include the `filename.h` header file and define variables of the given type. Then, it can operate on those variables only by using the operations defined in `filename.c`.

### 2.2. ADT operations
An ADT can define:
- **constructors** 
- **selectors**
- **predicates**
- **functions**
- **transformers**

### 2.3. Limits of ADT in C
There is no protection against an incorrect use of the ADT. Moreover, the internal structure of the object is visible by all the files. So, C proggramming language does not guarantee **information hiding**: an adequate level of protection. By including the header file (`#include "filename.h`), the client knows the structure of the defined type (`typedef` definition).

## 3. Examples
The [adt](../data-types/adt/) folder contains examples about ADT implementation.