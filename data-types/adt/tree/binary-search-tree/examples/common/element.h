#ifndef ELEMENT_H
#define ELEMENT_H

typedef char element;
typedef enum {false, true} boolean;

boolean isEqual(element, element);
boolean isLess(element, element);
boolean isLessOrEqual(element, element);
boolean isMajor(element, element);
boolean isMajorOrEqual(element, element);

element getElement(void);
void printElement(element);

#endif

// cd data-types/adt/tree/binary-search-tree/examples/common