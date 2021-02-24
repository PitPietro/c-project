/*
 * Play Melody in C
*/
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

#include "musical-frequencies.h"
#include "musical-names.h"

// global constants
#define MAX_NOTES 100
#define ROWS 2

// G3 (3rd string - guidar)
float happyBirthday[ROWS][MAX_NOTES] = {
  {PAUSE, G3, G3, A3, G3, C4, B3, G3, G3, A3, G3, D4, C4, G3, G3, G4, E4, C4, B3, A3, F4, F4, E4, C4, D4, C4, END},
  {HALF, D_EIGHTH, SIXTEENTH, QUARTER, QUARTER, QUARTER, HALF, D_EIGHTH, SIXTEENTH, QUARTER, QUARTER, QUARTER, HALF, D_EIGHTH, SIXTEENTH, QUARTER, QUARTER, QUARTER, QUARTER, HALF, D_EIGHTH, SIXTEENTH, QUARTER, QUARTER, QUARTER, HALF, END}
};

float base[ROWS][MAX_NOTES] = {
  {B0, B0, B0, B0, END},
  {QUARTER, QUARTER, QUARTER, QUARTER, END}
};

/*
 * Translate BPM to the milliseconds of four musical measures
 *
 * i.e. 60 BPM = 1 second * 4 musical measures = 4 seconds = 4'000 ms 
*/
float BPMToMillisec(int bpm) {
    float beat_per_sec = (float)bpm / 60;
    float beat_per_millisec = beat_per_sec * 1000;    
    return beat_per_millisec * 4;
}

/*
 * Return the number of notes. The melody has MAX_NOTES dimension to fit
 * a large melody, but can be shorter, so it's important dot to play a lot
 * of useless pauses.
 * 
 * The melody must have END as the last element, it wouldn't be correct
 * to stop count the melody dimension when there's a PAUSE (or more pauses)
 */
int melodyDimension(float melody[2][MAX_NOTES]) {
    unsigned short int i, j;
    unsigned short int dims[ROWS] = {0, 0};
    
    for(i = 0; i < ROWS; i++) {
        j = 0;
        while(melody[i][j] != END) {
            j++;
        dims[i]++;
        }
    
        // for(j = 0; j < (sizeof(melody[i]) / sizeof(melody[i][0])); j++) {}
    }

    // notes must be as much as the durations
    if(dims[0] != dims[1]) {
        return -1;
    } else {
        return dims[0];
    }
}

/*
 * int nanosleep(const struct timespec *req, struct timespec *rem);
 * 
 * > DESCRIPTION
 * nanosleep() suspends the execution of the calling thread until either
 * at least the time specified in *req has elapsed, or the delivery of
 * a signal that triggers the invocation of a handler in the calling
 * thread or that terminates the process.
 * 
 * The structure timespec is used to specify intervals of time with nanosecond precision.
 * It is defined as follows:
 *
 * struct timespec { time_t tv_sec; long tv_nsec; };
 * 
 * link: https://stackoverflow.com/questions/1157209/is-there-an-alternative-sleep-function-in-c-to-milliseconds#1157217
*/
int msleep(long msec) {
    struct timespec ts;
    int res;

    if (msec < 0) {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);

    return res;
}

/*
 * play the melody
*/
void playMelody(float melody[2][MAX_NOTES]) {
    int dim = melodyDimension(melody);
    int thisNote;
    
    for (thisNote = 0; thisNote < dim; thisNote++) {
        float timeMillis = BPMToMillisec(DEFAULT_BPM);
        float noteDuration = timeMillis * melody[1][thisNote];

        printf("%d) %.02f Hz --> %.02f = %.02f * %.04f\n", thisNote, melody[0][thisNote], noteDuration, timeMillis, melody[1][thisNote]);
    
    
        // int nanosleep(const struct timespec *req, struct timespec *rem);


        msleep(noteDuration);

        // tone(buzzer, melody[0][thisNote]);
        // delay(noteDuration);
        // stop the tone playing
        // noTone(buzzer);
    }

    printf("_____\n\n");
}

int main() {
    // wait for 2 seconds
    // usleep(2000 * 1000);
    
    // make 4 bits
    playMelody(base);
    
    playMelody(happyBirthday);
}

// cd arduino-utility/output/buzzer-melody/play-melody
// gcc -o melody melody.c && ./melody 