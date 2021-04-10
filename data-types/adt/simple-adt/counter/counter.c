#include <stdio.h>
#include "counter.h"

void reset(counter *C) {
    *C = 0;
}

void increment(counter *C) {
    (*C)++;
}
void decrement(counter *C) {
    (*C)--;
}

void printCounter(counter C) {
    printf("\ncounter = %d\n", C);
}