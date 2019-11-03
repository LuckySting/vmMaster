#include "vmCore.h"
#include "conf.h"


Engine transporterE(TransporterEnPin, TransporterStepPin, ParkYDirPin);


DirectAccTask transporter1(&transporterE);
EndlessDirectMoveTask transporter2(&transporterE);
DirectAccTask transporter3(&transporterE);
asyncQueueTask transporterQ(&transporter1, &transporter2);
asyncQueueTask transporter(&transporterQ, &transporter3);

void transporterInit(Flag* drop) {
  transporter1.init(LOW, TransporterMaxDelay, TransporterWorkDelay);
  transporter2.init(LOW, TransporterWorkDelay);
  transporter3.init(LOW, TransporterWorkDelay, TransporterReverseMaxDelay);
  transporterQ.setDrop(drop);
}