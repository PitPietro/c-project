#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "temp-bin.h"
#include "temp-txt.h"


int main() {
    char bName[] = "TEMP.bin";
    char tName[] = "TEMP.txt";
    
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
    write_bin(myT, bName);

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    temperature readT[MAX];
    int num;
    
    num = read_bin(readT, bName);
    print_temps(readT, num);

    printf("\n|~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    print_temps(myT, MAX);
    write_txt(myT, tName);
    
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    temperature readTempTXT[MAX];
    int numT;
    
    numT = read_txt(readTempTXT, tName);
    print_temps(readTempTXT, numT);

    return 0;
}

// cd files/read-write-es/temperature
// gcc -o main main.c utils.c temp-bin.c temp-txt.c && ./main

// TODO Perform some actions (i.e. search for hottest day in a given city)