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
    element e;
    scanf("%d", &e);
    return e;
}

void print_element(element e) {
    printf("%d", e);
}

boolean is_null(element e) {
    // return (e == 0);
    if (e == 0) {
        return true;
    } else {
        return false;
    }
}

boolean is_identity_element(element e) {
    if (e == 1) {
        return true;
    } else {
        return false;
    }
}

element sum_elements(element e1, element e2) {
    return e1 + e2;
}

element multiply_elements(element e1, element e2) {
    return e1 * e2;
}

// cd data-types/adt/tree/binary-search-tree/examples/common