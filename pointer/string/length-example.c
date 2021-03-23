#include <stdio.h>

int lengthStringArray(char s[]) {
    int i;
    for(i = 0; s[i] != '\0'; i++);

    return i;
}

int lengthStringPointer(char *s) {
    int i;
    for(i = 0; *(s + i) != '\0'; i++);

    return i;
}

void main(void) {
    char word[] = "My Awesome String";

    printf("The length of '%s' is %d\n", word, lengthStringArray(word));
    printf("The length of '%s' is %d\n", word, lengthStringPointer(word));
}

// cd pointer/string/
// gcc -o le length-example.c && ./le