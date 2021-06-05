#include "element.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


boolean is_equal(element e1, element e2) {
    return (strcmp(e1.first_name, e2.first_name) && strcmp(e1.last_name, e2.last_name));
}

boolean is_null(element e) {
    return (strcmp(e.first_name, "") || strcmp(e.last_name, ""));
}

/**
 * Insert an element
 * @return the element
 */
element insert_element(void) {
    element e;

    printf("\nInsert first name: ");
    scanf("%s", e.first_name);

    printf("\nInsert last name: ");
    scanf("%s", e.last_name);

    printf("\nInsert phone number: ");
    scanf("%s", e.phone_number);

    return e;
}

/**
 * Insert 'first_name' and 'last_name' only, to delete the element from the list
 * @return element inserted from the user
 */
element insert_element_to_delete(void) {
    element e;

    printf("\nInsert first name: ");
    scanf("%s", e.first_name);

    printf("\nInsert last name: ");
    scanf("%s", e.last_name);

    strcpy(e.phone_number, "");

    return e;
}

void print_element(element e) {
    printf("%s %s %s", e.first_name, e.last_name, e.phone_number);
}

/**
 * Copy the element passed as parameter
 * @param e element to copy
 * @return copy of the parameter
 */
element copy_element(element e) {
    element aux;

    strcpy(aux.first_name, e.first_name);
    strcpy(aux.last_name, e.last_name);
    strcpy(aux.phone_number, e.phone_number);

    return aux;
}
