#include <stdio.h>
#include <stdlib.h>

void lowercase_alphabet() {
    int int_a = (int)'a';
    int int_z = (int)'z';

    int letter = int_a;

    while(letter <= int_z) {
        printf("%c -- %d\n", (char)letter, letter);
        letter++;
    } 
    
}

void uppercase_alphabet() {
    int intA = (int)'A';
    int intZ = (int)'Z';

    char letter = (char)intA;

    while((int)letter <= intZ) {
        printf("%c -- %d\n", letter, (int)letter);
        letter++;
    }
}

int main() {
    lowercase_alphabet();
    uppercase_alphabet();
    return 0;
}

// cd data-types/int/char
// gcc -o alphabet alphabet.c && ./alphabet

/*
Since characters are integers, any letters of the alphabet can be represented as a numerical value
*/