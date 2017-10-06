#include "SequenceAnimation.h"
#include <stdlib.h>
#include <Arduino.h>

void sequence(Adafruit_NeoPixel* strip, uint32_t c, uint8_t wait) {
    for (int j=0; j<10; j++) {  //do 10 cycles of alternations
        int sequence [4] = {2, 1, 3, 4};
        for (int q = 0; q < sizeof(sequence); q++)
        {
            for (uint16_t i=0; i < strip->numPixels(); i=i+4) {
                strip->setPixelColor(i+sequence[q]-1, c); //turn the sequence pixel on
            }
            strip->show();

            delay(wait);

            for (uint16_t i=0; i < strip->numPixels(); i=i+4) {
                strip->setPixelColor(i+sequence[q]-1, 0); //turn the squence pixel off
            }
            delay(wait);
        }
    }
}

void SequenceAnimation::drawFrame() {
    Adafruit_NeoPixel* strip = this->getStrip();
    sequence(strip, strip->Color(127, 0, 0), 200); // Red
    sequence(strip, strip->Color(0, 127, 0), 200); // Green
    sequence(strip, strip->Color(0, 0, 127), 200); // Blue
};
