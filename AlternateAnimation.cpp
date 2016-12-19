#include "AlternateAnimation.h"
#include <stdlib.h>
#include <Arduino.h>

void AlternateAnimation::drawFrame() {
    Adafruit_NeoPixel* strip = this->getStrip();
    uint32_t colors[] = {
        strip->Color(255, 0, 0),
        strip->Color(0, 255, 0)
    };
    uint16_t pixels = strip->numPixels();
    for (unsigned int colorIndex = 0 ; colorIndex < 4 ; colorIndex++) {
        for (uint16_t i = 0 ; i < pixels ; i++) {
            if (i % 2 == 0) {
                strip->setPixelColor(i, colors[colorIndex % 2]);
            }   
            else { 
                strip->setPixelColor(i, colors[(colorIndex + 1) % 2]);
            }
        }
        strip->show();
        delay(1000);
        
    }

};
