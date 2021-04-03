#include "element.h"

// ADT
typedef struct list_element {
    element value;
    struct list_element *next;
} item;

typedef item *list;

list insertAddressBook(list);
list deleteAddressBook(list);
void searchAddressBook(list);
// void printAddressBook(list);