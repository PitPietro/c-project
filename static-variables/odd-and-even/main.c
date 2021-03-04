#include <stdio.h>
#include "odds.h"

// the above line would lead to a linking error
// extern int lastOddValue;

void main(void){
	int i;
	for(i = 1; i < 10; i++) {
        printf("%d\n", nextOdd());
        // it's not possible to modify 'lastOddValue'
        // lastOddValue = 1;
    }
}

// cd static-variables/odd-and-even
// gcc -o odd-numbers main.c odds.c && ./odd-numbers