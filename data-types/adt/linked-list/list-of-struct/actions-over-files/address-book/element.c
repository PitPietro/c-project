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

element get_element(void) {
    element e;
    scanf("%s", e.first_name);
    scanf("%s", e.last_name);
    scanf("%d", &e.phone_number);
    return e;
}

void print_element(element e) {
    printf("%s %s %d", e.first_name, e.last_name, e.phone_number);
}