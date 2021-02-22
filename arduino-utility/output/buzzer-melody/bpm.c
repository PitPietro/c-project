/*
 * translate BPM to the milliseconds of four musical measures
 *
 * i.e. 4'000 ms = 4 seconds = 1 second * 4 musical measures = 60 BMP
*/
float BPMToMillisec(int bpm) {
    float beat_per_sec = (float)bpm / 60;
    float beat_per_millisec = beat_per_sec * 1000;
    float four_measures = beat_per_millisec * 4;
    
    // printf("%f\n", beat_per_sec);
    // printf("%f\n", beat_per_millisec);
    // printf("%f\n", four_measures);
    
    return four_measures;
}