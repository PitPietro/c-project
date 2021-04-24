#include "element.h"
#include <stdio.h>

element getElement(void) {
    element el;
    scanf("%c", &el);
    return el;
}

void printElement(element el) {
    printf("%c", el);
}

// cd data-types/adt/tree/binary-tree/examples/common