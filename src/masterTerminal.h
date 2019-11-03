#pragma once
#include "Arduino.h"
#include "conf.h"


class masterTerminal{
public:
    void isDoorClosed();
    void closeTheDoor();
    void openTheDoor();
    void getItem(uint8_t slotCode);
    void toggleGreen(uint8_t slotCode);
    void toggleRed(uint8_t slotCode);

    masterTerminal(){
    }

    ~masterTerminal(){
    }

    void check(){
        if(Serial.available() == 2){
            uint8_t cmd = Serial.read();
            uint8_t arg = Serial.read();

            switch (cmd)
            {
            case 0x10:
                isDoorClosed();
                break;

            case 0x11:
                closeTheDoor();
                break;

            case 0x12:
                openTheDoor();
                break;

            case 0x20:
                toggleGreen(arg);
                break;

            case 0x21:
                toggleRed(arg);
                break;

            case 0x00:
                getItem(arg);
                break;

            
            default:
                break;
            }
        }
        return 0;
    }
};