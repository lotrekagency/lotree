#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <setjmp.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#include "Animation.h"
#include "SlimArray.h"

#include "AlternateAnimation.h"
#include "JingleAnimation.h"
#include "TheaterChaseAnimation.h"
#include "ColorWipeAnimation.h"
#include "RainbowAnimation.h"

#define TOTAL_LEDS 180
#define PIN 6


SlimArray<Animation*> animations;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(TOTAL_LEDS, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
    strip.begin();
    strip.show();
    pinMode(A0, OUTPUT);
    animations.insert((new ColorWipeAnimation())->setStrip(&strip)->setRepetitions(4));
    animations.insert((new TheaterChaseAnimation())->setStrip(&strip)->setRepetitions(4));
    animations.insert(((new JingleAnimation())->setTonePin(A0))->setStrip(&strip)->setRepetitions(1));
    animations.insert((new RainbowAnimation())->setStrip(&strip)->setRepetitions(4));
    animations.insert((new AlternateAnimation())->setStrip(&strip)->setRepetitions(1));
}

void loop() {
    for (int i = 0 ; i < animations.getSize() ; i++) {
        animations.get(i)->animate();
    }
}
