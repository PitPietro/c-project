#ifndef ELEMENT_H
#define ELEMENT_H

typedef char element;
typedef enum {false, true} boolean;

boolean isLess(element, element);
boolean isEqual(element, element);
element getElement(void);
void printElement(element);

#endif

// cd data-types/adt/tree/binary-tree/examples/common