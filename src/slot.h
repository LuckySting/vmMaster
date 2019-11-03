#include "vmCore.h"
#include "conf.h"


Engine slotE(Slot00EnPin, Slot00StepPin, Slot00DirPin);

DirectAccTask slot1(&slotE);
EndlessDirectMoveTask slot2(&slotE);
DirectAccTask slot3(&slotE);
DirectMoveTask slot4(&slotE);
DirectAccTask slot5(&slotE);

asyncQueueTask slotQ1(&slot1, &slot2);
asyncQueueTask slotQ2(&slot3, &slot4);
asyncQueueTask slotQ3(&slotQ1, &slotQ2);
asyncQueueTask slot(&slotQ3, &slot5);




void slotInit(Flag* drop) {
  slot1.init(HIGH, ParkYMaxDelay, ParkYWorkDelay);
  slot2.init(HIGH, ParkYWorkDelay);
  slot3.init(LOW, ParkYReverseMaxDelay, ParkYReverseDelay);
  slot4.init(LOW, ParkYReversePath, ParkYReverseDelay);
  slot5.init(LOW, ParkYReverseDelay, ParkYReverseMaxDelay);
  slotQ1.setDrop(drop);
}