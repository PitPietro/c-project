// #include <stdio.h>

#define DIM 20

typedef struct {
    char first_name[20];
    char last_name[20];
    char phone_number[30];
} element;

// C language does not provide boolean data type by default
typedef enum {
    false, true
} boolean;

// methods about the element itself (not the whole linked list)

boolean is_first_name_equal(element, element);
boolean is_last_name_equal(element, element);
boolean is_phone_number_equal(element, element);
boolean is_equal(element, element);

boolean is_null(element);

// getters and setters
element insert_element(void);

element insert_first_and_last_name(void);

void print_element(element);

element copy_element(element);

