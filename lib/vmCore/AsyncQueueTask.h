#pragma once
#include "AsyncTask.h"
#include "Arduino.h"
#include "Flag.h"

class asyncQueueTask : public AsyncTask {
private:
    AsyncTask* current;
    AsyncTask* first;
    AsyncTask* last;
    Flag* drop;
public:
    asyncQueueTask(AsyncTask* first, AsyncTask* last){
        this->first = first;
        this->last = last;
        this->current = this->first;
        this->drop = nullptr;
    }

    void stop() final{
        this->first->stop();
        this->last->stop();
        this->current = this->first;
    }

    void setDrop(Flag* drop){
        this->drop = drop;
    }


    uint8_t update() final {
        if(this->current == nullptr){
            this->stop();
            return HIGH;
        }
        if(this->drop != nullptr && this->drop->get()){
            return HIGH;
        }
        uint8_t done = this->current->update();
        if (done) {
            if (this->current != this->last){
                this->current = this->last;
            } else {
                this->current = nullptr;
            }
        }
        return LOW;
    }
};