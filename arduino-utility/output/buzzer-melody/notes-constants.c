/*
 * Use the notes' constants to make a melody
 * 
 * |  American            |  British             |  time  |
 * |----------------------|----------------------|--------|
 * |  whole note          |  semibreve           |  4/4   |
 * |  half note           |  minim               |  2/4   |
 * |  quarter note        |  crotchet            |  1/4   |
 * |  eighth note         |  quaver              |  1/8   |
 * |  sixteenth note      |  semiquaver          |  1/16  |
 * |  thirty-second note  |  demisemiquaver      |  1/32  |
 * |  sixty-fourth note   |  hemidemisemiquaver  |  1/64  |
 * 
 * 
 * Please Note: the hemidemisemiquaver is also known as semidemisemiquaver
 * 
*/
#include <stdio.h>
#include "bpm.h"

#define DEFAULT_BPM 60
#define CONSTS 14

// 1/1 of 4'000 ms
const float WHOLE = 1;
const float HALF = 0.5; 
const float QUARTER = 0.25;
const float EIGHTH = 0.125;
const float SIXTEENTH = 0.0625;
const float THIRTY_SECOND = 0.03125;
const float SIXTY_FOURTH = 0.015625;

// dotted constants starts with capital 'D'
const float D_WHOLE = 1.5;
const float D_HALF = 0.75; 
const float D_QUARTER = 0.375;
const float D_EIGHTH = 0.1875;
const float D_SIXTEENTH = 0.09375;
const float D_THIRTY_SECOND = 0.046875;
const float D_SIXTY_FOURTH = 0.023438;

// test the constants on a time of 60 BPM 
int main() {
    // constants' names
    char names[CONSTS][21] = {
        "whole",
        "half",
        "quarter",
        "eighth",
        "sixteenth",
        "thirty-second",
        "sixty-fourth",
        "dotted whole",
        "dotted half",
        "dotted quarter",
        "dotted eighth",
        "dotted sixteenth",
        "dotted thirty-second",
        "dotted sixty-fourth",
    };

    float constants[CONSTS] = {
        WHOLE, HALF, QUARTER, EIGHTH, SIXTEENTH, THIRTY_SECOND, SIXTY_FOURTH,
        D_WHOLE, D_HALF, D_QUARTER, D_EIGHTH, D_SIXTEENTH, D_THIRTY_SECOND, D_SIXTY_FOURTH
    };

    // 4000 ms
    float fourBitsMillis = BPMToMillisec(DEFAULT_BPM);

    // test all the constants
    int i;
    for(int i = 0; i < CONSTS; i++) {
        float noteDuration = fourBitsMillis * constants[i];

        printf("%s = %f\n", names[i], noteDuration);
    }
}

// cd arduino-utility/output/buzzer-melody
// gcc -o k notes-constants.c bpm.c && ./k