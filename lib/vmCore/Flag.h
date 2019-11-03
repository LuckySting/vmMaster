#pragma once
#include "Arduino.h"

class Flag{
private:
    uint8_t value;
public:
    void set(uint8_t value){
        this->value = value;
    }
    uint8_t get(){
        return this->value;
    }
};