#pragma once
#include "Arduino.h"
#include "Engine.h"
#include "Flag.h"
#include "AsyncTask.h"

class DirectAccTask : public AsyncTask{
private:
    Engine* engine;
    uint8_t direction;
    uint16_t startDelay;
    uint16_t endDelay;
    uint16_t delay;
    short delta; 
public:
    DirectAccTask(Engine* engine){
        this->engine = engine;
    }

    void init(uint8_t direction, uint16_t startDelay, uint16_t endDelay) {
        this->startDelay = startDelay;
        this->delay = startDelay;
        this->endDelay = endDelay;
        this->delta = endDelay > startDelay ? 1 : -1;
        this->engine->setDelay(this->delay);
        this->direction = direction;
    }

    void stop() final{
        this->delay = this->startDelay;
        this->engine->dettach();
    }

    uint8_t update() final {
        if(this->delay != this->endDelay) {
            this->engine->attach();
            this->engine->setDirection(this->direction);
            this->engine->setDelay(this->delay);
            if (this->engine->step()) {
                this->delay+=delta;
            }
            return LOW;
        } else {
            this->stop();
            return HIGH;
        }
    } 
};