#include "RainbowAnimation.h"
#include <stdlib.h>
#include <Arduino.h>

uint32_t Wheel(Adafruit_NeoPixel* strip, byte WheelPos) {
    WheelPos = 255 - WheelPos;
    if(WheelPos < 85) {
        return strip->Color(255 - WheelPos * 3, 0, WheelPos * 3);
    }
    if(WheelPos < 170) {
        WheelPos -= 85;
        return strip->Color(0, WheelPos * 3, 255 - WheelPos * 3);
    }
    WheelPos -= 170;
    return strip->Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

void rainbow(Adafruit_NeoPixel* strip, uint8_t wait) {
    uint16_t i, j;
    for(j = 0; j < 256; j++) {
        for(i = 0; i < strip->numPixels(); i++) {
            strip->setPixelColor(i, Wheel(strip, (i + j) & 255));
        }
        strip->show();
        delay(wait);
    }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(Adafruit_NeoPixel* strip, uint8_t wait) {
    uint16_t i, j;
    for(j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
        for(i=0; i< strip->numPixels(); i++) {
            strip->setPixelColor(i, Wheel(strip, ((i * 256 / strip->numPixels()) + j) & 255));
        }
        strip->show();
        delay(wait);
    }
}


//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(Adafruit_NeoPixel* strip, uint8_t wait) {
    for (int j = 0; j < 256; j++) {     // cycle all 256 colors in the wheel
        for (int q = 0; q < 3; q++) {
            for (uint16_t i = 0; i < strip->numPixels(); i = i + 3) {
                strip->setPixelColor(i + q, Wheel(strip, (i + j) % 255));    //turn every third pixel on
            }
            strip->show();

            delay(wait);

            for (uint16_t i = 0; i < strip->numPixels(); i = i + 3) {
                strip->setPixelColor(i + q, 0);        //turn every third pixel off
            }
        }
    }
}

void RainbowAnimation::drawFrame() {
    Adafruit_NeoPixel* strip = this->getStrip();
    rainbow(strip, 20);
    rainbowCycle(strip, 20);
    theaterChaseRainbow(strip, 50);
};
