#pragma once
#include "Arduino.h"

class Engine {
private:
    uint8_t enablePin;
    uint8_t stepPin;
    uint8_t dirPin;
    uint8_t stepLvl;
    uint16_t delay_;
    uint64_t prevTime;
public:
    Engine(uint8_t enablePin, uint8_t stepPin, uint8_t dirPin) {
        pinMode(enablePin, OUTPUT);
        pinMode(stepPin, OUTPUT);
        pinMode(dirPin, OUTPUT);
        this->enablePin = enablePin;
        this->stepPin = stepPin;
        this->dirPin = dirPin;
        this->dettach();
    }
    void switchDrive(uint8_t enablePin, uint8_t stepPin, uint8_t dirPin){
        pinMode(enablePin, OUTPUT);
        pinMode(stepPin, OUTPUT);
        pinMode(dirPin, OUTPUT);
        this->enablePin = enablePin;
        this->stepPin = stepPin;
        this->dirPin = dirPin;
        this->dettach();
    }
    void setDirection(uint8_t direction){
        digitalWrite(this->dirPin, direction);
    }
    void setDelay(uint16_t delay_){
        this->delay_ = delay_;
    }
    void attach(){
        digitalWrite(this->enablePin, LOW);
    }

    void dettach(){
        digitalWrite(this->enablePin, HIGH);
    }
    uint8_t step(){
        uint64_t curTime = micros();
        if ((curTime - this->prevTime) >= delay_) {
            this->prevTime = curTime;
            this->stepLvl = !this->stepLvl;
            digitalWrite(this->stepPin, this->stepLvl);
            return HIGH;
        }
        return LOW;
    }
};