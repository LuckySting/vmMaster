#pragma once
#include "Arduino.h"
#include "Engine.h"
#include "Flag.h"
#include "AsyncTask.h"

class EndlessDirectMoveTask : public AsyncTask{
private:
    Engine* engine;
    uint8_t stepping;
    uint8_t direction;
public:
    EndlessDirectMoveTask(Engine* engine){
        this->engine = engine;
    }

    void init(uint8_t direction, uint16_t delay_) {
        this->stepping = true;
        this->direction = direction;
        this->engine->setDelay(delay_);
    }

    void stop() final{
        this->engine->dettach();
    }

    uint8_t update() final {
        if(this->stepping) {
            this->engine->attach();
            this->engine->setDirection(this->direction);
            this->engine->step();
            return LOW;
        } else {
            this->stop();
            return HIGH;
        }
    } 
};