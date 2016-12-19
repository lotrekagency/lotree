#include "ColorWipeAnimation.h"
#include <stdlib.h>
#include <Arduino.h>

void colorWipe(Adafruit_NeoPixel* strip, uint32_t c, uint8_t wait) {
    for(uint16_t i = 0; i < strip->numPixels(); i++) {
        strip->setPixelColor(i, c);
        strip->show();
        delay(wait);
    }
}

void ColorWipeAnimation::drawFrame() {
    Adafruit_NeoPixel* strip = this->getStrip();
    colorWipe(strip, strip->Color(255, 0, 0), 50); // Red
    colorWipe(strip, strip->Color(0, 255, 0), 50); // Green
    colorWipe(strip, strip->Color(0, 0, 255), 50); // Blue
};
