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
    int pause = 100;

    Adafruit_NeoPixel* strip = this->getStrip();
    uint16_t leds = strip->numPixels();
    uint32_t color = strip->Color(127, 127, 127);

    for (int i = 0; i < MAX_COUNT; i++) {
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
            for (int j = 0; j < 15; j++) {
                for (int q = 0; q < 3; q++) {
                    for (uint16_t r = 0; r < strip->numPixels(); r = r + 3) {
                        strip->setPixelColor(r + q, color);
                    }
                    strip->show();
                    for (uint16_t r = 0; r < strip->numPixels(); r = r + 3) {
                        strip->setPixelColor(r + q, 0);
                    }
                }
            }
        }

        for (uint16_t r = 0; r < strip->numPixels(); r++) {
            if (r % 2 == 0) {
                if (i % 2 == 0) {
                    strip->setPixelColor(r, color);
                } else {
                    strip->setPixelColor(r, 0);
                }
            } else {
                 if (i % 2 == 0) {
                    strip->setPixelColor(r, 0);
                } else {
                    strip->setPixelColor(r, color);
                }
            }
        }
        strip->show();
        delayMicroseconds(pause);
                
    }
};
