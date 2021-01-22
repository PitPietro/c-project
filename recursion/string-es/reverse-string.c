#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string-utils.h"

#define DIM 15

void reverse_string_static(char word[], int index) {
    // use a static variable
    static int i = 0;

    // end of the string 
    if(word[index] == '\0') {
        return;
    }

    reverse_string_static(word, index+1);

    if(i <= index) {
        swap(&word[i++], &word[index]);
    }
}

// this version is better than the once above because it avoid the use of a static variable
void reverse_string(char word[], int index, int length) {
    if (index < length) {
        swap(&word[index], &word[length]);

        reverse_string(word, index + 1, length - 1);
    }
}

int main() {
    char hello1[DIM] = "Hello, World!";
    char hello2[DIM], hello3[DIM];
    
    strcpy(hello2, hello1);
    strcpy(hello3, hello1);
    
    reverse_string_static(hello2, 0);
    reverse_string(hello3, 0, strlen(hello3) - 1);
    
    printf("%s\n%s\n%s\n", hello1, hello2, hello3);
    
    return 0;
}

// cd recursion/string-es
// gcc -o reverse-string reverse-string.c string-utils.c && ./reverse-string