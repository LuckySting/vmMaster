#pragma once
#include "Arduino.h"
#include "Flag.h"
#include "AsyncTask.h"


class SerialTask : public AsyncTask {
private:
    uint8_t msg;
public:
    SerialTask(uint8_t msg){
        this->msg = msg;
    }
    void stop() final{}
    uint8_t update() final {
        Serial.print(msg);
        return HIGH;
    }
};