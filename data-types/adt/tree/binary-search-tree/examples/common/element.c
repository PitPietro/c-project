#include "element.h"
#include <stdio.h>

boolean isEqual(element e1, element e2) {
    return (e1 == e2);
}

boolean isLess(element e1, element e2) {
    return (e1 < e2);
}

boolean isLessOrEqual(element e1, element e2) {
    if(e1 <= e2) {
        return true;
    } else {
        return false;
    }
}

boolean isMajor(element e1, element e2) {
    return (e1 > e2);
}

boolean isMajorOrEqual(element e1, element e2) {
    return (e1 >= e2);
}

element getElement(void) {
    element el;
    scanf("%d", &el);
    return el;
}

void printElement(element el) {
    printf("%d", el);
}

// cd data-types/adt/tree/binary-search-tree/examples/common