#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CITY 10
#define NAME 20
#define TIME 11
#define MAX 15
#define ADDR 50
const char fileName[] = "TEMP.bin";

// it contains the fields of a temperature record
typedef struct {
    double value; // temperature value
    unsigned short int day; // 1 - 7 (monday - sunday) it could become an Enum
    char city[CITY];
    char time[TIME]; // format: dd/MM/yyyy (m = minute, M = month)
} temperature;

typedef struct {
    char firstName[NAME];
    char lastName[NAME];
    int age;
    // TODO: Add the department with an Enum
    int salary;
} person;

void print_temps(temperature t[], int num) {
    int i;
    for(i = 0; i < num; i++) {
        printf("%lf ~ day: %d ~ where: %s ~ when: %s\n", t[i].value, t[i].day, t[i].city, t[i].time);
    }
}

void fake_insert(temperature t[]) {
    temperature tmp[MAX] = {
        {15.321398, 2, "Sidney", "15/01/2010"},
        {45.82354897, 1, "NewYork", "02/10/2007"},
        {-40.698773, 5, "Moscow", "05/03/2011"},
        {30.654074, 4, "Rome", "24/03/2015"},
        {20.230543, 7, "NewYork", "09/07/2014"},
        {-45.805632, 3, "Moscow", "06/10/2019"},
        {25.745622, 2, "Rome", "11/11/2020"},
        {15.345639, 1, "Sidney", "14/09/2008"},
        {-48.881232, 1, "Moscow", "05/01/2010"},
        {12.741258, 3, "Sidney", "15/12/2012"},
        {22.345159, 2, "NewYork", "04/12/2004"},
        {33.345753, 5, "Sidney", "25/10/2020"},
        {43.345021, 5, "NewYork", "13/05/2004"},
        {32.342339, 7, "Rome", "28/01/2010"},
        {-28.300932, 7, "Moscow", "19/11/2016"},
    };

    print_temps(tmp, MAX);

    t = tmp;
}

void write_bin(temperature t[]) {
    int i;
    FILE *fp;

    // open file
    if((fp = fopen(fileName, "wb")) == NULL) {
        exit(1);
    }

    i = fwrite(t, sizeof(temperature), MAX, fp);

    // do not wrote all the records
    if(i != MAX) {
        exit(3);
    }

    printf("%d records have been wrote to file.\n", i);

    // close file
    if(fclose(fp) != 0) {
        exit(2);
    }

}

int read_bin(temperature t[]) {
    int i;
    FILE *fp;

    // open file
    if((fp = fopen(fileName, "rb")) == NULL) {
        exit(1);
    }

    // read the temperature records
    i = fread(t, sizeof(temperature), MAX, fp);

    printf("%d records have been read from file.\n", i);

    // close file
    if(fclose(fp) != 0) {
        exit(2);
    }

    return i;
}

int main() {
    temperature myT[MAX] = {
        {15.321398, 2, "Sidney", "15/01/2010"},
        {45.82354897, 1, "NewYork", "02/10/2007"},
        {-40.698773, 5, "Moscow", "05/03/2011"},
        {30.654074, 4, "Rome", "24/03/2015"},
        {20.230543, 7, "NewYork", "09/07/2014"},
        {-45.805632, 3, "Moscow", "06/10/2019"},
        {25.745622, 2, "Rome", "11/11/2020"},
        {15.345639, 1, "Sidney", "14/09/2008"},
        {-48.881232, 1, "Moscow", "05/01/2010"},
        {12.741258, 3, "Sidney", "15/12/2012"},
        {22.345159, 2, "NewYork", "04/12/2004"},
        {33.345753, 5, "Sidney", "25/10/2020"},
        {43.345021, 5, "NewYork", "13/05/2004"},
        {32.342339, 7, "Rome", "28/01/2010"},
        {-28.300932, 7, "Moscow", "19/11/2016"},
    };

    print_temps(myT, MAX);
    write_bin(myT);

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    temperature readT[MAX];
    int num;
    
    num = read_bin(readT);
    print_temps(readT, num);
    
    return 0;
}

// cd files/read-write-es/temperature
// gcc -o main main.c && ./main

// TODO 1: Make it for txt file too
// TODO 2: Subdivide the project into different files
// TODO 3: Perform some actions (i.e. search for hottest day in a given city)