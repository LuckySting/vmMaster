#include "vmCore.h"
#include "conf.h"

Engine elevator2(ParkYEnPin, ParkYStepPin, ParkYDirPin);

DirectMoveTask ToLevel22(&elevator2);
DirectMoveTask ToLevel221(&elevator2);
DirectAccTask ToLevel23(&elevator2);
asyncQueueTask ToLevel2Q1(&ToLevel22, &ToLevel221);
asyncQueueTask ToLevel2(&ToLevel2Q1, &ToLevel23);

void toLevel2Init(){
    ToLevel22.init(LOW, 60000, ParkYWorkDelay);
    ToLevel221.init(LOW, 35000, ParkYWorkDelay);
    ToLevel23.init(LOW, ParkYWorkDelay, ParkYReverseMaxDelay);
}