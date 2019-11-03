#pragma once
#include "Flag.h"

class AsyncTask{
public:
    uint8_t virtual update();
    void virtual stop();
};