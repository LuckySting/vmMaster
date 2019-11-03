#include "vmCore.h"
#include "conf.h"


Engine elevator(ParkYEnPin, ParkYStepPin, ParkYDirPin);

DirectAccTask parkY1(&elevator);
EndlessDirectMoveTask parkY2(&elevator);
DirectAccTask parkY3(&elevator);
DirectAccTask parkY4(&elevator);
DirectMoveTask parkY5(&elevator);
asyncQueueTask parkQY1(&parkY1, &parkY2);
asyncQueueTask parkQY3(&parkY4, &parkY5);
asyncQueueTask parkQY2(&parkQY1, &parkY3);
asyncQueueTask parkY(&parkQY2, &parkQY3);

void parkYInit(Flag* drop) {
  parkY1.init(HIGH, ParkYMaxDelay, ParkYWorkDelay);
  parkY2.init(HIGH, ParkYWorkDelay);
  parkY3.init(HIGH, ParkYWorkDelay, ParkYReverseMaxDelay);
  parkY4.init(LOW, ParkYReverseMaxDelay, ParkYReverseDelay);
  parkY5.init(LOW, ParkYReversePath, ParkYReverseDelay);
  parkQY1.setDrop(drop);
}