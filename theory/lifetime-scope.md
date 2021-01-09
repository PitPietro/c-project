# Scope and Lifetime of a variabile

The lifetime is affected by the placement of the definition.
The scope is affected by the placement of the declaration.

## 1. Lifetime

The lifetime of an object is the time in which memory is reserved while the program is executing. It can be:

1. static
2. automatic
3. dynamic

### 1.1. Static Objects

The memory for static objects is allocated at compile/link time. Their addresses are fixed by the linker based on the **Linker Control File** (LCF). 

**Please Note**: The LCF is also known as *linker-script file*, *linker configuration file* or *scatter-loading description file*. 

The static region is subdivided into two further sections:

- initialised-definitions
- uninitialised-definitions

```c
// initialised-definitions
int alpha = 25;

// uninitialized-definitions
int beta;

// ...
// functions, main and so on
```

It would not be unexpected for the address of `alpha` and `beta` to not be adjacent to each other in SRAM. The  uninitialised-definitions’ section is commonly known as the .bss or ZI  section. The initialised-definitions’ section is commonly known as the  .data or RW section.
The initial value of `beta` will be zero.

#### 1.1.1. Static Local Variables

The keyword static can be applied to a local variable: it changes the objects lifetime from automatic to static. The memory is then allocated at compiler/link time and its address in memory is fixed. As the memory is static these local variables retain their values from function call to function call. The local static is initialised only the first call of the function. 

```c
#include <stdio.h>

void function() {
    // static local
    static int sL = 10;

    // automatic local
    int aL = 10;
    printf("static = %d, automatic = %d\n", sL, aL);
    
    // increase the value of the variables
    sL++;
    aL++;
}

int main() {
    function();
    function();
    function();

    return 0;
}
```

The output will be:

```bash
static = 10, automatic = 10
static = 11, automatic = 10
static = 12, automatic = 10
```

**Please Note**: Local statics must be avoided while implementing *multi-tasking* and *multi-threadning*. 

### 1.2. Automatic Objects

Variables defined within functions, parameters and any temporary-returned-object (TRO) from a non-void function are classed as automatic.
The memory for these objects is allocated from the stack. For parameters and TRO’s the memory is usually allocated by the calling function, while for local objects, memory is allocated once the function is called. This enables a function to call itself and make *recursion*.

If an automatic variable is not explicitly initialised, the initial value is indeterminate and therefore should never be read before an assignment. 
If the automatic variable is explicitly initialised, the memory is reinitialised on each call of the function.
The location and size of the stack are typically defined using the LCF.

### 1.3. Dynamic Objects

When calling on `malloc`, `calloc `or `realloc`, these functions return an address (`void*`) for a block of dynamically allocated memory.
The lifetime of this memory is from allocation until the call to either `free ` or `realloc  `the memory.

The `realloc  `function takes an allocated memory block and expands (or contracts) it to a bigger (or smaller) size. This may involve moving the chunk of memory and copying over the old contents. When this is done, the old contents are automatically freed.

The contents of the memory return from `malloc ` are indeterminate. For `calloc  `the memory is initialised to all zeros. If `realloc ` expands the allocated memory area, then the contents of the extra expended area are indeterminate.
The size and location of the heap are usually defined in the LCF.

## 2. Scope

The scope of an object is the part of the program where the variable can be accessed. It can be:

1. File scope
2. Block scope

A variable must be declared before it is accessed, hence its scope is determined by the placement of its declaration.

### 2.1. File Scope

Any variable declared with file scope can be accessed by any function defined after the declaration.

### 2.2. Block Scope

Block scope is defined by the pairing of the curly braces `{` and `}` .
A variable declared within a block can only be accessed within that block.
Note that a local static variable has block scope even though it has static lifetime.

Inside a function, further localised (inner) scopes can be introduced, e.g. (a loop inside a function).

```c
void f() {
    int i;
    int a = 15;
    
    for(i = 0; i < a; i++) {
        int k = i + a;
    }
    
    // this is NOT allowed
    printf("k = %d", k);
}
```

The variables `i` and `a` can be accessed within the *for* loop, but the variable `k` cannot be accessed outside the *for* loop.

#### 2.2.1. Overlapping Scopes

```c
int a = 150;

int main() {
    int a = 30;
    printf("Inside main, a = %d\n", a);
    
    return 0;
}
```

The output will be:

```bash
Inside main, a = 30
```

An inner scope identifier always hides an outer scope identifier. The block-scoped identifier `a` hides the file-scoped identifier `a` .
The file-scoped ` k` is still in scope but is rendered invisible, so it's a very bad practice to overlap scopes.

### 2.3. Scope of Dynamic Objects

A dynamic object doesn’t actually have scope. Its scope is determinated by the scope of any pointer holding the address of the dynamically allocated memory. As long as the pointer is in scope, it can be dereferenced and the memory accessed.

### 2.4. External and Internal Linkage

If a variable is defined with file scope in one file, but is required in another, then it can be brought into scope using the `extern` storage-class specifier.

```c
// fun.c
int a = 120;
```

```c
// main.c
external int a;

int main() {
    // ...
}
```

Off course, you need to compile both the files:

```bash
gcc -o main main.c fun.c
```

If you need a variable that has static lifetime and file scope, you can use the `static` keyword to affect scope rather than lifetime. If a file scoped variable is tagged as static then it has an *internal linkage*.

```c
// hello.c
int a = 120; // external linkage – global scope
static int b; // internal linkage – this-file scope
```

If another file tried to declare `b` as `extern`, then it would result in a **link-time error**. Note that internal linkage can also be applied to functions. All functions have external linkage by default, so it is very good practice to declare a function as static if it is only being used with the current file.

## 3. Links

I took inspiration from:

- [blog.feabhas.com](https://blog.feabhas.com/2010/09/scope-and-lifetime-of-variables-in-c/)