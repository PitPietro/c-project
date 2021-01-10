# Expressions

## 1. Natural numbers
A digit (bit) can only have the value of 0 or 1.
Using *n* digits:
- the maximum number of configurations is `2^n`
- the maximum representable number is `(2^n) -1`

The unsigned integers are:
- `unsigned char` - 0 .. 255 - 8 bit
- `unsigned short` - 0 .. 65535 - 16 bit
- `unsigned int` - / - 16 or 32 bit
- `unsigned long` - / 32 bit
- `unsigned long long` - / - 64 bit

For `unsigned char`, the maximum number of configurations is `2^8` and the maximum representable number is `(2^8) -1`.

`unsigned int` is the data type that is more efficient on the CPU.

### 1.1. Overflow
If you try to represent the number `(2^n)` (or greater), you'll be send back to the first configuration: as many zeros as `n`.
If you try to represent the number `(2^n) - (2^n) -1` (or smaller), you'll be send back to the last configuration: `(2^n) -1`.

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