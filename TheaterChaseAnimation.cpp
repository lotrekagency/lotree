#include "TheaterChaseAnimation.h"
#include <stdlib.h>
#include <Arduino.h>

void theaterChase(Adafruit_NeoPixel* strip, uint32_t c, uint8_t wait) {
    for (int j=0; j<10; j++) {  //do 10 cycles of chasing
        for (int q=0; q < 3; q++) {
            for (uint16_t i=0; i < strip->numPixels(); i=i+3) {
                strip->setPixelColor(i+q, c); //turn every third pixel on
            }
            strip->show();

            delay(wait);

            for (uint16_t i=0; i < strip->numPixels(); i=i+3) {
                strip->setPixelColor(i+q, 0); //turn every third pixel off
            }
        }
    }
}

void TheaterChaseAnimation::drawFrame() {
    Adafruit_NeoPixel* strip = this->getStrip();
    theaterChase(strip, strip->Color(127, 127, 127), 50); // White
    theaterChase(strip, strip->Color(127, 0, 0), 50); // Red
    theaterChase(strip, strip->Color(0, 0, 127), 50); // Blue
};
