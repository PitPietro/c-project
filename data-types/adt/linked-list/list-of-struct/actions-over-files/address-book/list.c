#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * Insert the element on the top of the list
 * @param l list where to perform the insertion
 * @param e element to add to the list
 * @return the updated list
 */
list insert_in_head(list l, element e) {
    list aux;

    // allocate auxiliary list in HEAP memory
    aux = (list) malloc(sizeof(item));

    // copy the value
    aux->value = copy_element(e);
    aux->next = l;

    return aux;
}

/**
 * Recursively insert an element to the list
 * @param l list where to insert the element
 * @param e element to insert
 * @return updated list
 */
list recursive_element_insertion(list l, element e) {
    if (l == NULL) {
        l = insert_in_head(l, e);
    } else {
        if (strcmp(e.first_name, l->value.first_name) <= 0) {
            l = insert_in_head(l, e);
        } else {
            l->next = recursive_element_insertion(l->next, e);
        }
    }

    return l;
}

/**
 * Input mask for 'recursive_element_insertion()' function.
 * This functions reads an element from the user input and
 * then call the recursive insertion.
 * @param l list to update
 * @return updated list
 */
list insert_address_book(list l) {
    element e = insert_element();
    return recursive_element_insertion(l, e);
}

/**
 * Delete an element from the list
 * @param l list to update
 * @param e element to delete
 * @return updated list
 */
list delete_element(list l, element e) {
    int found = 0;
    list aux = l, prev = NULL;

    if (aux != NULL) {
        if (strcmp(aux->value.first_name, e.first_name) == 0) {
            printf("\n%s %s has been deleted\n", aux->value.first_name, aux->value.last_name);
            l = aux->next;
            free(aux);
        }
    } else {
        while ((aux != NULL) && (!found)) {
            if (strcmp(aux->value.first_name, e.first_name) == 0)
                found = 1;
            else {
                prev = aux;
                aux = aux->next;
            }
        }
        if (aux != NULL) {
            printf("\n%s %s has been deleted\n", aux->value.first_name, aux->value.last_name);
            prev->next = aux->next;
            free(aux);
        }
    }

    return l;
}

/**
 * Input mask for 'delete_element()' function.
 * This functions reads an element (first and
 * last name only) from the user input and call
 * the deletion function.
 * @param l list to update
 * @return updated list
 */
list delete_address_book(list l) {
    element e = insert_first_and_last_name();
    return delete_element(l, e);
}

/**
 * Find an element inside the list
 * @param e
 * @param l
 * @return
 */
list find_element(element e, list l) {
    list L = l;

    int found = 0;

    while ((L != NULL) && (!found)) {
        if ((!strcmp(e.first_name, L->value.first_name)) && (!strcmp(e.last_name, L->value.last_name))) {
            found = 1;
        } else {
            L = L->next;
        }
    }

    if (found)
        return L;
    else
        return NULL;
}

/**
 * Input mask for 'find_element()' function.
 * This functions reads an element (first and
 * last name only) from the user input and call
 * the search function.
 * @param l list where to search the element
 */
void search_address_book(list l) {
    list k = NULL;

    element e = insert_first_and_last_name();

    k = find_element(e, l);

    if (k != NULL) {
        printf("\nThe phone number of %s %s is %s", k->value.first_name, k->value.last_name, k->value.phone_number);
    } else {
        printf("\n%s %s not found\n", e.first_name, e.last_name);
    }
}

/**
 * Print the list in an iterative way.
 * @param l list to print
 */
void print_address_book(list l) {
    while (l != NULL) {
        print_element(l->value);
        l = l->next;
    }
}