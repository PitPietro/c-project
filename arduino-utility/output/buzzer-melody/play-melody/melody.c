/*
 * Play Melody in C
*/
#include <stdio.h>
#include <unistd.h>
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
  // return the number of notes
  // both the 1st and the 2nd arrays must have the same lenght

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

void playMelody(float melody[2][MAX_NOTES]) {
  // melody contains the notes (in the 1st array) and the notes' duration (in the 2nd array)
  // iterate over the notes of the melody

  int dim = melodyDimension(melody);
  int thisNote;
  
  for (thisNote = 0; thisNote < dim; thisNote++) {
    float timeMillis = BPMToMillisec(DEFAULT_BPM);
    float noteDuration = timeMillis * melody[1][thisNote];

    printf("%d) %.02f Hz --> %.02f = %.02f * %.04f\n", thisNote, melody[0][thisNote], noteDuration, timeMillis, melody[1][thisNote]);
    
    // use int usleep(useconds_t usec); but taking noteDuration * 1000
    // since usleep takes in microseconds

    usleep(noteDuration * 1000);

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