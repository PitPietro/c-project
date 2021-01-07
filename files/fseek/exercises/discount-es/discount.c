#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "discount.h"

const char fileName[] = "products.bin";

void print_products(product p[], int num) {
    for(int i = 0; i < num; i++) {
        printf("%s - %d\n", p[i].name, p[i].price);
    }
}

void fake_insert_products(product p[]) {
    // fakes an insertion of MAX products
    strcpy(p[0].name, "socs");
    strcpy(p[1].name, "t-shirt");
    strcpy(p[2].name, "pants");
    strcpy(p[3].name, "belt");
    strcpy(p[4].name, "jacket");

    p[0].price = 40;
    p[1].price = 120;
    p[2].price = 150;
    p[3].price = 80;
    p[4].price = 290;
}

void write_bin(product p[]) {
    int i;
    FILE *fp;

    // open file
    if((fp = fopen(fileName, "wb")) == NULL) {
        exit(1);
    }

    // write
    i = fwrite(p, sizeof(product), MAX, fp);

    if(i != MAX) {
        exit(3);
    }

    // close
    if(fclose(fp) != 0) {
        exit(2);
    }
}

int read_bin(product p[]) {
    int i;
    FILE *fp;

    // open file
    if((fp = fopen(fileName, "rb")) == NULL) {
        exit(1);
    }

    // read
    i = fread(p, sizeof(product), MAX, fp);

    // close
    if(fclose(fp) != 0) {
        exit(2);
    }

    return i;
}

void apply_discount(product p[]) {
    int i = 0;
    FILE *fp;

    // open file
    if((fp = fopen(fileName, "r+b")) == NULL) {
        exit(1);
    }

    while(fread(&p[i], sizeof(product), 1, fp) == 1) {
        if(p[i].price > THRESHOLD) {
            p[i].price = p[i].price - (p[i].price * 0.2);
            fseek(fp, -(long)sizeof(product), SEEK_CUR);

            fwrite(&p[i], sizeof(product), 1, fp);

            fseek(fp, 0, SEEK_CUR);
        }

        i++;
    }

    // close
    if(fclose(fp) != 0) {
        exit(2);
    }
}