// #include <stdio.h>

#define DIM 20

typedef struct
{
    char first_name[20];
    char last_name[20];
    int phone_number[30];
} element;

// C language does not provide boolean data type by default
typedef enum {false, true} boolean;

// methods about the element itselt (not the whole linked list)

// comparison algorithm
boolean is_equal(element, element);
boolean is_null(element);

// getter/setter
element get_element(void);
void print_element(element);

