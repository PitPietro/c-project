#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "short-int.h"

void write_short_int_to_bin(short int element) {
    FILE *fp;

    if((fp = fopen("short-int.bin", "wb")) == NULL) {
        printf("Error while opening the file\n");
        exit(1);
    }
    
    printf("Writing %d into the bin file.\n", element);
    fwrite(&element, sizeof(short int), DIM, fp);

    if(fclose(fp) != 0) {
        printf("Error: wrong file closure!\n");
        exit(2);
    }
}

void write_short_int_to_txt(short int element) {
    FILE *fp;

    if((fp = fopen("short-int.txt", "wt")) == NULL) {
        printf("Error while opening the file\n");
        exit(1);
    }

    printf("Writing %d into the txt file.\n", element);
    fprintf(fp, "%d", element);

    if(fclose(fp) != 0) {
        printf("Error: wrong file closure!\n");
        exit(2);
    }
}

/*
Those functions will create short-int.txt and short-int.bin files.
By running an `ls -l` command on the current directory you'll se that
the binary file weighs 2 bytes while the text file weighs 5 bytes.
The txt file stores each digit of the number as a character.
The bin file stores the entire number as a single entity. 
*/