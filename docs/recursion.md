# Recursion
A function that call itself inside this body, is called *recursive*.

Recursion is based on the principle of mathematical induction of Giuseppe Peano. If it's possible to demostrate that:
1. a given P property holds for `x = a` (exit condition)
2. assming that P holds for `x`
3. then it holds for `x + 1` too
4. then P holds for all `x >= a`


**Exit Condition**:
Recursive functions must have at least one **exit condition**, that's where the function stops to call itself e terminate its execution.

The recursive calls decompose the problem without evaluating any results. Once the exit condition is satisfied, the result is evaluated backwards while the calls close.


## 1. Non-linear Recursion
Each invocation causes more than a call to the recursive function.
It's the case of Fibonacci series, `fib(n)` is defined as:
- `0` for `n = 0`
- `1` for `n = 1`
- `fib(n-1) + fib(n-2)` for all `n` natural number `!= 0, != 1`

## 2. Tail

### 2.1. Tail Optimization
Also known as **Last Call Optimization**.

Recursion introduces some inefficiencies:
- chains of activation record inside the RAM memory
- creation of new records that takes time

If a function `foo()` invoke another function `bar()` and this one is the last operation to perform before finishing the execution, then the activation record of the invoking function `foo()` can be replaced by the activation record of invoked function `bar()`.

### 2.2. Tail Recursion
In this specific type of recursion, the recursive call must be the last operation. Before Tail Recursion, is mandatory to study the *iterative* way to write a function.

This time, the result is evaluated forward (i.e. `result = result * i`).

Each iteration is an *iterative computational process*. After each step, is avalable a partial result.

It's possible to make an iterative computational process using tail recursive functions. There must be an hoarder variable that holds the partial result, which is updated after every iteration.

```c
while( /* condition */ ) {
    /* cicle body */
}
```

Becomes:
```c
if( /* condition */ ) {
    /* cicle body */

    /* recursive call */
}
```

Note that the recursive call must always be the last instruction.

However, each function that make a recursive call, suspends itself, whait for the ending of the recursive call and then ends.
It doen't make any other operations.

A recursion that make an iterative computational process is an apparent recursion.

## 3. Examples
### 3.1. The factorial
This is one of the most suitable example.
The factorial of a number *n* is represented with `n!` and is defined as:
- `n(n-1)!` for `n > 0`
- `1` for `n = 0` (exit condition)


```c
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}
``` 

```c
// iterative factorial
int factorial(int n) {
    int result = 1;
    int i = 1;

    while(i <= n) {
        result *= i;
        i++;
    }

    return result;
}
```

```c
// tail recursive
int factorial(int n, int result, int iterator) {
    int res = result;
    int i = iterator;

    while(i <= n) {
        res *= i;
        i++;
        return tail_fact(n, res, i);
    }

    return res;
}
```