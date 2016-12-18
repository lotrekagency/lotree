#ifndef ANIMATION_CLASS
#define ANIMATION_CLASS

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif


class Animation {
    private:
        unsigned int repetitions;
        Adafruit_NeoPixel* strip;
    public:
        virtual void drawFrame() = 0;
        Animation* setRepetitions(unsigned int repetitions) {this->repetitions = repetitions; return this;};
        unsigned int getRepetitions() {return this->repetitions;};
        Animation* setStrip(Adafruit_NeoPixel* strip) {this->strip = strip; return this;};
        Adafruit_NeoPixel* getStrip() {return this->strip;};
        void animate() {
            for (int i = 0 ; i < getRepetitions() ; i++) {
                drawFrame();
            }
        }
};

#endif
