# Left and Right Values

## 1. lvalue
It refers to memory location which identifies an object.

An expression referring to modifiable location is called **modifiable l-value**. It cannot have: an array type, an incomplete type, a type with the `const` attribute.
Structures and unions that are modifiable l-values, cannot have any members with the `const` attribute.

The name of the identifier denotes a storage location, while the value of the variable is the value stored at that location.
An identifier is a modifiable l-value if it refers to a memory location and if its type is: arithmetic, structure, union, pointer.

In **C** programming language, the concept was renamed as *locator value*, and referred to expressions that designate objects.
The l-value is:
1. name of the variable of any type (i.e, an identifier of int, float, pointer, structure or union type).
2. A subscript (`[ ]`) expression that doesn't evaluate to an array.
3. A unary-indirection (`*`) expression that doesn't refer to an array
4. An l-value expression in parentheses.
5. A const object (a **nonmodifiable l-value**).
6. The result of indirection through a pointer, provided that it isn’t a function pointer.
7. The result of member access through pointer(`->` or `.`)

```c
// 1. identifier of int and float
int a;
float b;

// l-value can appear on the right of the expression
int beta = a;

// Compilation error:
// As assignment is trying to change the value of assignment operator
9 = b;

```
