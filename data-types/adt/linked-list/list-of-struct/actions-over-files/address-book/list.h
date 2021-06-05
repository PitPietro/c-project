#include "element.h"

// ADT
typedef struct list_element {
    element value;
    struct list_element *next;
} item;

typedef item *list;

list insert_in_head(list, element);

list recursive_element_insertion(list, element);

list insert_address_book(list);

list delete_element(list, element);

list delete_address_book(list);

list find_element(element, list);

void search_address_book(list);

void print_address_book(list);