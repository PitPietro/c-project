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

### 1.2. Dereferencing

The **dereferencing**  operator, the start symbol `*`, is applied to a pointer and returns the value stored in the pointed cell.

### 1.3. Referencing

The **referencing** operator, the commercial and `&`, is applied to a variable and returns its address.