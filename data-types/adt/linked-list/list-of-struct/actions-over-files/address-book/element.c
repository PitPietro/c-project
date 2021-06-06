#include "element.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Compare 'first_name' of the elements passed as parameters
 * @param e1 element 1
 * @param e2 element 2
 * @return 'true' if their 'first_name' is equal, otherwise 'false'
 */
boolean is_first_name_equal(element e1, element e2) {
    return strcmp(e1.first_name, e2.first_name);
}

/**
 * Compare 'last_name' of the elements passed as parameters
 * @param e1 element 1
 * @param e2 element 2
 * @return 'true' if their 'last_name' is equal, otherwise 'false'
 */
boolean is_last_name_equal(element e1, element e2) {
    return strcmp(e1.last_name, e2.last_name);
}

/**
 * Compare 'phone_number' of the elements passed as parameters
 * @param e1 element 1
 * @param e2 element 2
 * @return 'true' if their 'phone_number' is equal, otherwise 'false'
 */
boolean is_phone_number_equal(element e1, element e2) {
    return strcmp(e1.phone_number, e2.phone_number);
}

/**
 * Check if the elements passed as parameters are equal
 * @param e1 element 1
 * @param e2 element 2
 * @return 'true' if the elements are equal, otherwise 'false'
 */
boolean is_equal(element e1, element e2) {
    return (is_first_name_equal(e1, e2) && is_last_name_equal(e1, e2) && is_phone_number_equal(e1, e2));
}

/**
 * Check if the element is null: all its property must be != ""
 * @param e element
 * @return 'true' if the element is null (empty, in this case), otherwise 'false'
 */
boolean is_null(element e) {
    return (strcmp(e.first_name, "") || strcmp(e.last_name, "") || strcmp(e.phone_number, ""));
}

/**
 * Insert an element
 * @return the element
 */
element insert_element(void) {
    element e;

    printf("\nInsert first name: ");
    scanf("%s", e.first_name);

    printf("Insert last name: ");
    scanf("%s", e.last_name);

    printf("Insert phone number: ");
    scanf("%s", e.phone_number);

    return e;
}

/**
 * Insert 'first_name' and 'last_name' only, to delete the element from the list
 * @return element inserted from the user
 */
element insert_first_and_last_name(void) {
    element e;

    printf("\nInsert first name: ");
    scanf("%s", e.first_name);

    printf("Insert last name: ");
    scanf("%s", e.last_name);

    strcpy(e.phone_number, "");

    return e;
}

/**
 * Print out the element passed as parameter
 * @param e element
 */
void print_element(element e) {
    printf("%s %s %s\n", e.first_name, e.last_name, e.phone_number);
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
