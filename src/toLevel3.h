#include "vmCore.h"
#include "conf.h"

Engine elevator3(ParkYEnPin, ParkYStepPin, ParkYDirPin);

DirectAccTask ToLevel31(&elevator3);
DirectMoveTask ToLevel32(&elevator3);
DirectMoveTask ToLevel33(&elevator3);
DirectMoveTask ToLevel34(&elevator3);
DirectMoveTask ToLevel35(&elevator3);
DirectAccTask ToLevel36(&elevator3);
asyncQueueTask ToLevel3Q1(&ToLevel31, &ToLevel32);
asyncQueueTask ToLevel3Q2(&ToLevel33, &ToLevel34);
asyncQueueTask ToLevel3Q3(&ToLevel35, &ToLevel36);
asyncQueueTask ToLevel3Q4(&ToLevel3Q1, &ToLevel3Q2);
asyncQueueTask ToLevel3(&ToLevel3Q3, &ToLevel3Q4);

void toLevel3Init(){
    ToLevel31.init(LOW, ParkYMaxDelay, ParkYWorkDelay);
    ToLevel32.init(LOW, 60000, ParkYWorkDelay);
    ToLevel33.init(LOW, 60000, ParkYWorkDelay);
    ToLevel34.init(LOW, 60000, ParkYWorkDelay);
    ToLevel35.init(LOW, 15000, ParkYWorkDelay);
    ToLevel36.init(LOW, ParkYWorkDelay, ParkYReverseMaxDelay);
}