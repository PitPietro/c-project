#include <stdio.h>
int lastOddValue = 0;

/*
 * odd numbers are in the form 2k + 1 with k in Z = {..., -2, -1, 0, 1, 2, ...}
*/
int nextOdd(void) {
    return 1 + 2 * lastOddValue++;
}

// cd static-variables/odd-and-even