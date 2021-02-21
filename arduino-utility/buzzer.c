#include <stdio.h>

#define DIM 10

/*
 * Translate BPM to the milliseconds of four musical measures
 *
 * i.e. 4'000 ms = 4 seconds = 1 second * 4 musical measures = 60 BMP
*/
float BPMToMillisec(int bpm) {
    float beat_per_sec = (float)bpm / 60;
    float beat_per_millisec = beat_per_sec * 1000;
    
    // printf("%f\n", beat_per_sec);
    // printf("%f\n", beat_per_millisec);
    // printf("%f\n", beat_per_millisec * 4);
    
    return beat_per_millisec * 4;
}

int main() {
    int bpms[DIM] = {60, 70, 80, 90, 100, 110, 120, 130, 140, 150};
    int i;

    for(i = 0; i < DIM; i++) {
        float musical = BPMToMillisec(bpms[i]);
        printf("%d) %d BPM = %f\n", i, bpms[i], musical);
    }
}

// cd arduino-utility
// gcc -o buzzer buzzer.c && ./buzzer