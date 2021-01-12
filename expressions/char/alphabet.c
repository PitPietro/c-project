#include <stdio.h>

void placeholderUppercase() {
    unsigned char i, c = 'A';

    printf("\nPlaceholder uppercase:\n");

    for(i = c; i <= 'Z'; i++) {
        printf("%c ~ %d\n", i, i);
    }
}

void placeholderLowercase() {
    unsigned char i, c = 'a';

    printf("\nPlaceholder lowercase:\n");

    for(i = c; i <= 'z'; i++) {
        printf("%c ~ %d\n", i, i);
    }
}

void castToIntUppercase() {
    unsigned char c = 'A';
    int i;

    printf("\nCast to Int uppercase:\n");

    for(i = (int)c; i <= (int)'Z'; i++) {
        printf("%c ~ %d\n", (char)i, i);
    }
}

void castToIntLowercase() {
    unsigned char c = 'a';
    int i;

    printf("\nCast to Int lowercase:\n");

    for(i = (int)c; i <= (int)'z'; i++) {
        printf("%c ~ %d\n", (char)i, i);
    }
}