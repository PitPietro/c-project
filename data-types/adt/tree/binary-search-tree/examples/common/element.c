#include "element.h"
#include <stdio.h>

boolean is_equal(element e1, element e2) {
    return (e1 == e2);
}

boolean is_less(element e1, element e2) {
    return (e1 < e2);
}

boolean is_less_or_equal(element e1, element e2) {
    if(e1 <= e2) {
        return true;
    } else {
        return false;
    }
}

boolean is_major(element e1, element e2) {
    return (e1 > e2);
}

boolean is_major_or_equal(element e1, element e2) {
    return (e1 >= e2);
}

element get_element(void) {
    element el;
    scanf("%d", &el);
    return el;
}

void print_element(element el) {
    printf("%d", el);
}

// cd data-types/adt/tree/binary-search-tree/examples/common