#pragma once
#include "Arduino.h"
#include "conf.h"
#include "FastLED.h"

class Led{
private:

public:
    Led(){}

    void greenOn(uint8_t led, CRGB* leds){
        for(uint8_t i = led; i<led+2; i++){
            leds[i] = CRGB::Green;
        }
        FastLED.show();
    }

    void redOn(uint8_t led, CRGB* leds){
        for(uint8_t i = led; i<led+2; i++){
            leds[i] = CRGB::Red;
        }
        FastLED.show();
    }

    void off(CRGB* leds){
        for(uint8_t i = 0; i<LedNum; i++){
            leds[i] = CRGB::Black;
        }
        FastLED.show();
    }

};