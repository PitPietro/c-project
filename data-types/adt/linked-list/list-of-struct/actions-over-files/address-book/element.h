// #include <stdio.h>

#define DIM 20

typedef struct
{
    char first_name[20];
    char last_name[20];
    char phone_number[30];
} element;

// C language does not provide boolean data type by default
typedef enum {false, true} boolean;

// methods about the element itself (not the whole linked list)

// comparison algorithm
boolean is_equal(element, element);
boolean is_null(element);

// getter/setter
element insert_element(void);
element insert_element_to_delete(void);
void print_element(element);
element copy_element(element);

