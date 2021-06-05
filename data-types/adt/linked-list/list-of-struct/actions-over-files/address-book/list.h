#include "element.h"

// ADT
typedef struct list_element {
    element value;
    struct list_element *next;
} item;

typedef item *list;

list insert_address_book(list);
list delete_address_book(list);
void search_address_book(list);
void print_address_book(list);