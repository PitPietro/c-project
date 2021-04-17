#include "element.h"
#include <stdio.h>

boolean isEqual(element e1, element e2) {
    return (e1 == e2);
    /*
    if (e1 == e2) return true;
    else return false;
    */
}

boolean isLess(element e1, element e2) {
    return (e1 < e2);
}

element getElement(void) {
    element el;
    scanf("%c", &el);
    return el;
}

void printElement(element el) {
    printf("%c\t", el);
}

// cd data-types/adt/tree/binary-tree/examples/common