#include <stdio.h>
#include "odds.h"
#include "evens.h"

// the above line would lead to a linking error
// extern int lastOddValue;

void main(void){
	int i;
	for(i = 1; i < 10; i++) {
        printf("%d\n", nextOdd());
        // it's not possible to modify 'lastOddValue'
        // lastOddValue = 1;
    }

    for(i = 1; i < 10; i++) {
        printf("%d\n", nextEven());
        // it's not possible to modify 'lastEvenValue'
        // lastEvenValue = 1;
    }
}

// cd static-variables/odd-and-even
// gcc -o odd-and-even-numbers main.c odds.c evens.c && ./odd-and-even-numbers