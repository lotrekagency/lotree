#include "JingleAnimation.h"
#include <stdlib.h>
#include <Arduino.h>

#define  C     2100
#define  D     1870
#define  E     1670
#define  f     1580
#define  G     1400
#define  R     0

void JingleAnimation::drawFrame() {

    if(this->restartCounter != 0) {
        this->restartCounter--;
        return;
    } else {
        this->restartCounter = ANIMATION_PAUSE_CYCLES;
    }

    int melody[] = {E, E, E, R,
      E, E, E, R,
      E, G, C, D, E, R,
      f, f, f,f, f, E, E, E, E, D , D, E, D, R, G ,R,
      E, E, E, R,
      E, E, E, R,
      E, G, C, D, E, R,
      f, f, f,f, f, E, E, E,
      G, G, f, D, C, R };


    int note = 0;
    long duration  = 0;
    int rest_count = 100;
    int MAX_COUNT = sizeof(melody) / 2;
    long tempo = 10000;
    int beat = 0;
    int pause = 1000;

    for (int i=0; i<MAX_COUNT; i++) {
        note = melody[i];
        beat = 50;

        duration = beat * tempo; // Set up timing

        long elapsed_time = 0;

        if (note > 0) {
            while (elapsed_time < duration) {
                digitalWrite(this->tonePin,HIGH);
                delayMicroseconds(note / 2);
                digitalWrite(this->tonePin, LOW);
                delayMicroseconds(note / 2);
                elapsed_time += (note);
            }
        } else {
            for (int j = 0; j < rest_count; j++) {
                delayMicroseconds(duration);
            }
        }
        uint16_t leds = this->getStrip()->numPixels();
        for (uint16_t led = 0 ; led < leds ; led++) {
            if (led != this->tonePin)
                digitalWrite(led, HIGH);
        }
        // A pause between notes...
        delayMicroseconds(pause);
        for (int led = 0 ; led < leds ; led++) {
            if (led != this->tonePin)
                digitalWrite(led, LOW);
        }
    }
};
