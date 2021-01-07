#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uppercase.h"

const char fileName[] = "message.txt";

void make_uppercase() {
    char letter;
    FILE *fp;

    // open file
    if((fp = fopen(fileName, "r+")) == NULL) {
        exit(1);
    }

    while(fscanf(fp, "%c", &letter) != EOF) {
        // printf("letter: %c\n", letter);
        if((letter <= 'z') && (letter >= 'a')) {
            fseek(fp, ftell(fp) - 1, SEEK_SET);
            fprintf(fp, "%c", letter + ('A'-'a'));
            fseek(fp, 0, SEEK_CUR);
        }
    }

    // close
    if(fclose(fp) != 0) {
        exit(2);
    }
}