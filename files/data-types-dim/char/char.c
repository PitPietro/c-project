#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "char.h"

void write_char_to_bin(char element) {
    FILE *fp;

    if((fp = fopen("char.bin", "wb")) == NULL) {
        printf("Error while opening the file\n");
        exit(1);
    }
    
    printf("Writing %c into the bin file.\n", element);
    fwrite(&element, sizeof(char), DIM, fp);

    if(fclose(fp) != 0) {
        printf("Error: wrong file closure!\n");
        exit(2);
    }
}

void write_char_to_txt(char element) {
    FILE *fp;

    if((fp = fopen("char.txt", "wt")) == NULL) {
        printf("Error while opening the file\n");
        exit(1);
    }

    printf("Writing %c into the txt file.\n", element);
    fprintf(fp, "%c", element);

    if(fclose(fp) != 0) {
        printf("Error: wrong file closure!\n");
        exit(2);
    }
}

/*
Those functions will create char.txt and char.bin files.
The binary file weighs 1 byte and the text file, too. 
*/