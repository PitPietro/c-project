#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void write_bin(temperature t[], char fileName[]) {
    int i;
    FILE *fp;

    // open file
    if((fp = fopen(fileName, "wb")) == NULL) {
        printf("Error while opening the file\n");
        exit(1);
    }

    i = fwrite(t, sizeof(temperature), MAX, fp);

    // do not wrote all the records
    if(i != MAX) {
        exit(3);
    }

    printf("%d records have been wrote to %s\n", i, fileName);

    // close file
    if(fclose(fp) != 0) {
        printf("Error while closing the file\n");
        exit(2);
    }

}

int read_bin(temperature t[], char fileName[]) {
    int i;
    FILE *fp;

    // open file
    if((fp = fopen(fileName, "rb")) == NULL) {
        printf("Error while opening the file\n");
        exit(1);
    }

    // read the temperature records
    i = fread(t, sizeof(temperature), MAX, fp);

    printf("%d records have been read from %s\n", i, fileName);

    // close file
    if(fclose(fp) != 0) {
        printf("Error while closing the file\n");
        exit(2);
    }

    return i;
}