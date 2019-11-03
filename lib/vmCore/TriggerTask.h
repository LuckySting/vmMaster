#pragma once
#include "Arduino.h"
#include "Flag.h"
#include "AsyncTask.h"

uint8_t dgRead(uint8_t pin){
  return analogRead(pin) < 500;
}

class TriggerTask : public AsyncTask {
private:
    uint8_t pin;
    uint8_t triggerValue;
    uint8_t analog;
    Flag* flag;
public:
    TriggerTask(Flag* flag, uint8_t pin, uint8_t triggerValue, uint8_t analog = false){
        this->pin = pin;
        this->triggerValue = triggerValue;
        this->flag = flag;
        this->analog = analog;
    }
    void stop() final{}
    uint8_t update() final {
        uint8_t value;
        if (this->analog) {
            value = dgRead(this->pin);
        } else {
            value = digitalRead(this->pin);
        }
         
        this->flag->set(value == this->triggerValue);
        return value;
    }
};