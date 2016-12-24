# lotree

Lotrek's Xmas tree, made with Arduino and a led strip

## Install

- Install [Arduino IDE](https://www.arduino.cc/en/Main/Software)
- Install [Adafruit Neopixel libraries](https://github.com/adafruit/Adafruit_NeoPixel)

## How to compile

- Open lotree.ino with Arduino IDE
- Compile and upload

## Create your own animations

To create your own animation, start defining two files

- MyAnimation.h that contains your header
```
#ifndef ALTERNATE_ANIMATION_CLASS
#define ALTERNATE_ANIMATION_CLASS

#include "Animation.h"

class MyAnimation: public Animation {
    public:
        void drawFrame();
};

#endif
```
- MyAnimation.cpp that contains your core
```
#include "MyAnimation.h"
#include <stdlib.h>
#include <Arduino.h>

void MyAnimation::drawFrame() {
    Adafruit_NeoPixel* strip = this->getStrip();
    uint32_t color = strip->Color(255, 0, 0); // RGB
    uint16_t pixels = strip->numPixels();
    for (uint16_t i = 0 ; i < pixels ; i++) {
        strip->setPixelColor(i, color);
    }
    strip->show();
};
```
When you use
```
this->getStrip();
```
you get the reference to the current Adafruit_NeoPixel object.

When you want to define a new color, using the RGB schema, use:
```
uint32_t color = strip->Color(255, 0, 0);
```
When you're done with setting your pixel, execute
```
strip->show();
```
to show the pixels.

Now you can include this animation in the main process (lotree.ino)
```
#include "MyAnimation.h"

void setup() {
    // ...
    animations.insert((new MyAnimation())->setStrip(&strip)->setRepetitions(4));
}
```
As you can see you need to set the current strip and the repetitions for the current animation.

## License

MIT © Lotrek
