# Expressions

## 1. Natural Numbers

### 1.1. Represent a natural number
A digit (bit) can only have the value of 0 or 1.
Using *n* digits:
- the maximum number of configurations is `2^n`
- the maximum representable number is `(2^n) -1`

The unsigned integers are:
- `unsigned char` ~ 0 .. 255 ~ 8 bit
- `unsigned short` ~ 0 .. 65535 ~ 16 bit
- `unsigned int` ~ / ~ 16 or 32 bit
- `unsigned long` ~ 0 .. 4294967295 ~ 32 bit (somethimes 64 bit)
- `unsigned long long` ~ 0 .. 18446744073709551615 ~ 64 bit

For `unsigned char`, the maximum number of configurations is `2^8` and the maximum representable number is `(2^8) -1`.

`unsigned int` is the data type that is more efficient on the CPU.

### 1.2. Overflow of natural number
If you try to represent the number `(2^n)` (or greater), you'll be send back to the first configuration: as many zeros as `n`.
If you try to represent the number `(2^n) - (2^n) - 1 = 0 - 1` (or smaller), you'll be send back to the last configuration: `(2^n) -1`.

Let's make a couple of examples with `unsigned char` data type:
```c
int main() {
    unsigned char a, b;

    a = 255;
    b = a + 1;

    printf("a = %d\n", a);
    printf("%d+1 = %d\n", a, b);
}
```

It will give as result:
```bash
a = 255
255 + 1 = 0
```

```c
int main() {
    unsigned char a, b;

    a = 0;
    b = a - 1;

    printf("a = %d\n", a);
    printf("%d+1 = %d\n", a, b);
}
```

It will give as result:
```bash
a = 0
0 - 1 = 255
```

The overflow errors are not captured by the compiler because it would take a lot of time (and slow down the program) to check for each assignment not to cause overflow. Since the C programming language was designed to be fast, it's up to the programmer to make those types of checks.

## 2. Relative Numbers
They are also called *integer relative numbers*, *integer numbers*.

### 2.1. Represent a relative number
To represent "signed" numbers, it was decided to reserve half of configurations for the numbers minor than zero and reserve half of configurations for the numbers major or equal zero.

Since a digit (bit) can only have the value of 0 or 1 and using *n* digits:
- the maximum number of configurations is `2^n`
- the maximum number of configurations for negative numbers are `(2^n)/2` so `2^(n-1)`
- the maximum number of configurations for positive (and equal to zero) numbers are `(2^n)/2` so `2^(n-1)`
- the maximum representable negative number is `-2^(n-1)`
- the maximum representable positive number is `2^(n-1)-1`

For example, `char` data type is still represented with 8 bit (just as `unsigned char`).
It has `2^8` configurations: `2^7` are reserved for the negative numbers and `2^7` are reserved for positive (and equal to zero) numbers. So it has a range from `-128` to `127`.

The signed integers are:
- `char` ~ -128 .. 127 ~ 8 bit
- `short (int)` ~ -32768 .. 32767 ~ 16 bit
- `int` ~ / ~ 16 or 32 bit
- `long (int)` ~ -2147483648 .. 2147483647 ~ 32 bit
- `long long (int)` ~ -9223372036854775808 .. 9223372036854775807 ~ 64 bit

### 2.2. Overflow of relative number
If you try to represent the number `2^(n-1)` (or greater), you'll be send back to the first configuration: `-2^(n-1)`
If you try to represent the number `-2^(n-1) - 1` (or smaller), you'll be send back to the last configuration: `2^(n-1) - 1`.

Let's make a couple of examples with `char` data type:
```c
int main() {
    char a, b;

    a = 127;
    b = a + 1;

    printf("a = %d\n", a);
    printf("%d+1 = %d\n", a, b);
}
```

It will give as result:
```bash
a = 127
127 + 1 = -128
```

```c
int main() {
    char a, b;

    a = -128;
    b = a - 1;

    printf("a = %d\n", a);
    printf("%d+1 = %d\n", a, b);
}
```

It will give as result:
```bash
a = -128
-128 - 1 = 127
```

### 2.3 Represent characters using char
Characters are represented with a single byte.
A char can be interpreted as:
1. integer (from -128 to 127 or from 0 to 255) using the `%d` placeholder
2. character (ASCII code) using the `%c` placeholder

```c
#include <stdio.h>

int main() {
    char c = 64;

    printf("%c - %d\n", c, c);    
}
```

It will give as result:
```bash
@ - 64
```

In ASCII, from 0 to 32 there are the so called "transparent codes", they do not show a character but perform some other operations.
i.e. code 10 is new line (`\n`), 32 is the space (` `)

The characters are represented between single quotes: `' ... '`.
Some special characters can not be represented between them and need a back-slash after the first single quote:
- `'\n'` ~ new line
- `'\t'` ~ tab
- `'\''` ~ single quote
- `'\"'` ~ double quote
- `'\\'` ~ back-slash

## 3. Real Numbers
They are called *floating point numbers* becase the floating point (comma, decimal point) position depends on the expontent.

### 2.1. Represent a real number
It is represented using the scientific representation: `m * 10^(exp)` (using base 10).
Where **m** is the "mantissa" and **exp** is the expontent of 10.

The number of digits reserved for:
- the mantissa define the number precision.
- the expontent define the maximum representable number.

Some examples of floating points are:
```bash
6.8900000 * 10^4 = 68900.00
12.300 * 10^2 = 1230.0
```

The floating point numbers are:
- `float` ~ 32 bit ~ %f
- `double` ~ 64 bit ~ %lf
- `long double` ~ 80 bit ~ %lf

They can have different syntaxes:
- 45.2
- 65E3 = 65 * 10^3
- 5.7E4 = 5.7 * 10^4
- 809.7E-2 = 809.7 * 10^(-2)

## 4. Homogeneous & Heterogeneous Expression
An expression can be:
- homogeneous: all the operands have the same type (i.e. `10 + 5`, `14.9 / 6.7`)
- heterogeneous: the operands have different types (i.e. `2 + 3.8`, `18.6/3`, ...)
### 4.1. Overloading of Operators
Primitive operations associated with different types are denoted with the same symbol: i.e. to sum a coumple of numbers you'll always use the symbol `+`, wheather they're int, float or of any other type.

How does the compiler knows which algorithm to use? (sum between int, sum between float, ...).

C programming language establish which algorithm to use based on the type of the operands.
The operators (`+`, `-`, `*`, `/`, ...) have multiple meaning and that's why this section is about **overloading of operators**.

### 4.2. Types Conversion
In C language, are executable the expressions (even the heterogeneous ones) in which all referenced types are compatible. Types are compatible if after the application of automatic implicit conversion rule, the expression between the types is homogeneous.

### 4.3. Implicit Conversion Rule
Each operand of type `char` or `short` is converted to `int` type.
If the expression is still heterogeneous, the further conversions follows this hierarchy:
```c
int < long < float < double < long double
```

Each conversion from a lower type to an higher type is called **promotion**.
After a promotion, the compiler checks if the expression is homogeneous and evaluate the result of the operation.

Sometimes, the implicit conversion can lead to a loss of information if a variable have to move a step back in the hierarchy. It will trigger a **warning** but not an error.
i.e. from `float` to `int`, the decial part of the numer will be lost and `double` to `float` can lead to a loss of information too, since the `double` variable can store a bigger decimal part than `float`.

**Please Note**:
Even `int` to `float` can lead to a loss of information if the bits reserved for the mantissa of the float are less than the ones reserved for the integer number.
In this case, the less significant bits are lost.
### 4.4. Conversion During Assignments
During an assignment, the variable and the expression must have the same type.
In case they:
- are not compatible (e.i. an integer plus an array of char) you'll have compile-time error
- are compatible (e.i. float and double) the compiler tries to make the implicit conversions

```c
int main() {
    char c = 110;
    short s;
    float f;

    // c: char --> short
    s = c + 10;

    // c: char --> short --> --> int --> float
    f = c;

    f = 15.8;

    // Warning! truncation: 0.8 will be lost --> s = 15
    s = f;
}

```

### 4.5. Casting
In any expression is possible to force a conversion using the **cast** operator: it is used to avoid the warning.

It uses this syntax:
```bash
( <type_to_cast_to> ) <expression>
```

It could be usefull in many situation.
If, for example, you want to evaluate `2^n` with `n > 15` and save the value to a variable of type *long*:

```c
int main() {
    int i;
    long L;
    
    // 2^15
    i = 32768;
    // 2^16
    L = i * 2;
    printf("2^15 = %d\t2^16 = %ld\n", i, L);

    // 2^16
    i = L;
    // 2^17
    L = i * 2;
    printf("2^16 = %d\t2^17 = %ld\n", i, L); 
}

// cd expressions/cast-operator
```

It will give as result:
```bash
2^15 = 32768    2^16 = 65536
2^16 = 65536    2^17 = 0
```

The second time it tries to evaluate `L = i * i`, it triggers an overflow, since an integer variable can not handle such a large number. Using the cast operator it's possible to avoid it:

```c
int main() {
    int i;
    long L;
    
    // ...

    // i = 2^16 = 65536
    i = L;

    // 2^17
    L = ((long) i) * 2;
    printf("2^16 = %d\t2^17 = %ld\n", i, L); 
}
```

It will give as result:
```bash
2^15 = 32768    2^16 = 65536
2^16 = 65536    2^17 = 131072
```

Another meaningfull example is the arithmetic mean as you can see in `expressions/cast-operator/arithmetic-mean.c`.

### 4.6. Priority of Operators
To avoid confusion during operations, has been made a list of priority.
The **priority** specifies the order of evaluation of operators in case they're different from eachother.
The **associativity** specifies the order of evaluation of operators in case they have equal priority. An operator can be associative to the left (almost all) or to the right. (ie. the sum is associative to the left: `15 - 3 + 4 = (15 - 3) + 4`).

Of course, priority and associativity can be changed using round brackets.

Even the assignment (`a = b`) is an operation and consequently provide a result, which is the value of the expression on the right of the equal sign. It is associative to the right.
It's possible to make **multiple assignments** on the same row of code:
```c
int a, b;

a = b = 15;
printf("%d = %d", a, b);
```

It will give as result:
```bash
15 = 15
```

### 4.7 Concatenated Expression
The concatenation operator is the **comma**. All the expressions are evalated from left to right.
