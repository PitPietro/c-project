#include <stdio.h>

void main (void) {
    char vector[] = "ABCDE";
    int i = 3;
    
    // ways to print the i-th element of the vector[] array
    printf("%c - %c - %c - %c\n", vector[i],         vector[3],         i[vector],         3[vector]         );
    printf("%c - %c - %c - %c\n", *(vector + i),     *(vector + 3),     *(i + vector),     *(3 + vector)     );
    printf("%c - %c - %c - %c\n", *(&vector[0] + i), *(&vector[0] + 3), *(i + &vector[0]), *(3 + &vector[0]) );
}

// cd pointer/string/
// gcc -o pe print-elements.c && ./pe