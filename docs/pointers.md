# Pointers

The **pointer** stores address of memories.

```bash
<PointedElementType> *<PointerName>
```

For example:

```c
int *p;
int height = 145;

// referencing
// p points to the memory cell of 'height' 
p = &height;

// dereferencing
// change the value of 'height' from its pointer
*p = 220;
```

## 1. Operators

### 1.1. Assignment

The assignment operator, the `=` sign, can be used only between pointers that points to the same type.

`NULL` is a constant to specify that the address is null.

**Please Note**: It's not allowed the assignment between pointers of compatible types (i. e. `char` and `int` or `float` and `double`).

### 1.2. Referencing

The **referencing** operator, the  `&`, is applied to a variable and returns its address. It can be used to associate a pointer to a variable's address.

```c
int intVar = 45;
int * pointerToInt;

int pointerToInt = &intVar;

```



### 1.3. Dereferencing

The **dereferencing**  operator, the start symbol `*`, is applied to a pointer and returns the value stored in the pointed cell. It can be used to modify the value of the pointed variable.

```c
*pointerToInt = 22;
// intVar changed its value from 45 to 22
```

 

### 1.4 Arithmetical Operators

The `+` and `-` operators.

### 1.5. Relational Operators

- `>` and `<`
- `==` and `!=`

## 2. Arrays and Pointers

Let's declare an array of a given number of elements and a pointer, both of the same type.

```c
int vector[10];

int *pointerToInt;
```

The elements of `vector[]` are stored in consecutive cells inside the memory. The dimension depends on the type of the elements.

The name of the array is itself the constant address of the first element of the consecutive cells where the array is stored.

So `vector` is a **pointer** to `int`.

```c
// the statement below is true
vector = &vector[0];

// this is allowed: vector is pointer to int
pointerToInt = vector;

// this will lead to an ERROR
vector = pointerToInt;
```

### 2.1. Length of a string

Let's apply the concept above with the `char` data type and the strings.

The file [length-example.c](https://github.com/PitPietro/c-project/blob/main/pointer/string/length-example.c) shows that `char s[]` and `char *s` are equal. 

### 2.2. Dereferencing

The `*` operator applied to a pointer, access to the pointed variable.

The `[]` operator applied to an array name (using in integer `i` as index), access the `i`-th element of the array.

### 2.3. Arithmetic of Pointers

`*` and `[]` operators are interchangeable.

```c
*vector = vector[0] = *(vector + 0);
// ...
vector[i] = *(&vector[0] + i);
vector[i] = *(vector + i);
```

The files [print-elements.c](https://github.com/PitPietro/c-project/blob/main/pointer/string/print-elements.c) shows many different ways to print the `i`-th element of the `vector[]` array. 

Note that the difference between pointers produces a warning.

Allowed operations:

```c
int *p,*q;
p = q;
p - q;
p -= q;
```

### 2.4. Priority of Operators

`[]` has major priority than `*`

1. `p` is a vector of ten  pointers to `char`.

```c
char *p[10];
```



2. `p` is pointer to a vector of `char`

```c
char (*p)[10];
// or
typedef char V[10];
V *p;
```



### 2.5. Pointers to struct

The `->` allows to access to a field of a struct referenced by a pointer.

```c
typedef struct {
    int field1, field2
} DataType;

DataType s, *p;

p = &s;

(*p).field1;
// is equal to
p->field1;
```

