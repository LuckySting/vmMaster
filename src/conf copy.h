////////// LEDs: //////////
// LED00
#define LedNum 5


////////// ParkY: //////////
// engine:
#define ParkYEnPin 38
#define ParkYDirPin A1
#define ParkYStepPin A0
// ender:
#define ParkYEnderPin 14
#define ParkYEnderLevel LOW
#define ParkYEnderAnalogMode false
// reverse
#define ParkYMaxDelay 400
#define ParkYWorkDelay 20
#define ParkYReverseMaxDelay 400
#define ParkYReverseDelay 20
#define ParkYReversePath 2000



////////// Transporter: //////////
// engine:
#define TransporterEnPin A2
#define TransporterDirPin A7
#define TransporterStepPin A6
// ender:
#define TransporterEnderPin 3
#define TransporterEnderLevel LOW
#define TransporterEnderAnalogMode false
// reverse
#define TransporterMaxDelay 1000
#define TransporterWorkDelay 200
#define TransporterReverseMaxDelay 1000
#define TransporterReverseDelay 500



////////// Slots: //////////
#define SlotsDirPin 41 5
// ender:
#define SlotsEnderPin 3 
#define SlotsEnderLevel HIGH
#define SlotsEnderAnalogMode false
// reverse
#define SlotsMaxDelay 2000
#define SlotsWorkDelay 400
#define SlotsReverseMaxDelay 2000
#define SlotsReverseDelay 500
#define SlotsReversePath 500

///////// Column 0
#define Col0EnPin 49 8

///////// Row 0
#define Row0StepPin 50 2

///////// Slot 00
#define LED_PIN00


///////// masterTerminal /////////
#define baudRate 9600
#define PARK_Y 1
#define UNLOAD_SLOT00 2
#define TOGGLE_GREEN00 3
#define IS_DOOR_CLOSED 4
#define CLOSE_THE_DOOR 5
#define OPEN_THE_DOOR 6
#define OK 99
#define BAD 100