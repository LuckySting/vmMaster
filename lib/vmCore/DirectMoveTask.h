#pragma once
#include "Arduino.h"
#include "Engine.h"
#include "Flag.h"
#include "AsyncTask.h"

class DirectMoveTask : public AsyncTask{
private:
    Engine* engine;
    uint8_t direction;
    uint16_t steps;
    uint16_t storedSteps;
public:
    DirectMoveTask(Engine* engine){
        this->engine = engine;
    }

    void init(uint8_t direction, uint16_t steps, uint16_t delay_) {
        this->steps = steps;
        this->storedSteps = steps;
        this->direction = direction;
        this->engine->setDelay(delay_);
    }

    void stop() final{
        this->steps = storedSteps;
        this->engine->dettach();
    }

    uint8_t update() final {
        if(this->steps > 0) {
            this->engine->attach();
            this->engine->setDirection(direction);
            if (this->engine->step()) {
                this->steps--;
            }
            return LOW;
        } else {
            stop();
            return HIGH;
        }
    } 
};