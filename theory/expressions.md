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