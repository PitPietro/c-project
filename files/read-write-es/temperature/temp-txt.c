#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void write_txt(temperature t[], char fileName[]) {
    int i;
    FILE *fp;

    // open file
    if((fp = fopen(fileName, "wt")) == NULL) {
        printf("Error while opening the file\n");
        exit(1);
    }

    for(i = 0; i < MAX; i++) {
        fprintf(fp, "%lf ", t[i].value);
        fprintf(fp, "%hn ", &t[i].day);
        fprintf(fp, "%s ", t[i].city);
        fprintf(fp, "%s\n", t[i].time);
    }

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

int read_txt(temperature t[], char fileName[]) {
    int i = 0;
    FILE *fp;

    // open file
    if((fp = fopen(fileName, "rt")) == NULL) {
        printf("Error while opening the file\n");
        exit(1);
    }

    // read the temperature records
    while(fscanf(fp, "%lf ", &t[i].value) != EOF) {
        fscanf(fp, "%hn ", &t[i].day);
        fscanf(fp, "%s ", t[i].city);
        fscanf(fp, "%s\n", t[i].time);
        i++;
    }

    printf("%d records have been read from %s\n", i, fileName);

    // close file
    if(fclose(fp) != 0) {
        printf("Error while closing the file\n");
        exit(2);
    }

    return i;
}