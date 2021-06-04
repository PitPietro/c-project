#ifndef ELEMENT_H
#define ELEMENT_H

typedef int element;
typedef enum {false, true} boolean;

// comparison algorithms
boolean is_equal(element, element);
boolean is_less(element, element);
boolean is_less_or_equal(element, element);
boolean is_major(element, element);
boolean is_major_or_equal(element, element);

// state about the element
element get_element(void);
void print_element(element);
boolean is_null(element);
boolean is_identity_element(element);
element sum_elements(element, element);
element multiply_elements(element, element);

#endif

// cd data-types/adt/tree/binary-search-tree/examples/common