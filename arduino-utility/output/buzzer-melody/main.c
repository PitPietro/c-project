#include <stdio.h>
#include "bpm.h"

#define BPM_TEST_DIM 10

int main() {
    int bpms[BPM_TEST_DIM] = {60, 70, 80, 90, 100, 110, 120, 130, 140, 150};
    int i;

    for(i = 0; i < BPM_TEST_DIM; i++) {
        float musical = BPMToMillisec(bpms[i]);
        printf("%d) %d BPM = %f\n", i, bpms[i], musical);
    }
}

// cd arduino-utility/output/buzzer-melody
// gcc -o buzzer main.c bpm.c && ./buzzer