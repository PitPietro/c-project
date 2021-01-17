#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void print_temps(temperature t[], int num) {
    int i;
    for(i = 0; i < num; i++) {
        printf("%lf ~ day: %d ~ where: %s ~ when: %s\n", t[i].value, t[i].day, t[i].city, t[i].time);
    }
}