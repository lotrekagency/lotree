# lotree

Lotrek's Xmas tree, made with Arduino and some [BTF-LIGHTING strips (Led WS2812b)](https://www.amazon.it/dp/B01CDTEJBG/ref=cm_sw_r_tw_dp_U_x_MF5qAbYGFVZF0)

## Install

- Install [Arduino IDE](https://www.arduino.cc/en/Main/Software)
- Install [Adafruit Neopixel libraries](https://github.com/adafruit/Adafruit_NeoPixel)

## Build and upload

- Open lotree.ino with Arduino IDE
- Compile and upload

## Create your animations

To create your custom animation, you need to define two files

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

Now you need to include the animation file header in the main process (lotree.ino) and register it!
```
#include "MyAnimation.h"

void setup() {
    // ...
    animations.insert((new MyAnimation())->setStrip(&strip)->setRepetitions(4));
}
```
As you can see you need to set the current strip reference and the times you want to repeat your animation.

## License

MIT © Lotrek
