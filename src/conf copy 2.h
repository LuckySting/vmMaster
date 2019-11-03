////////// LEDs: //////////
// LED00
#define LedNum 5


////////// ParkY: //////////
// engine:
#define ParkYEnPin 8
#define ParkYDirPin 4
#define ParkYStepPin 7
// ender:
#define ParkYEnderPin A7
#define ParkYEnderLevel LOW
#define ParkYEnderAnalogMode true
// reverse
#define ParkYMaxDelay 1000
#define ParkYWorkDelay 500
#define ParkYReverseMaxDelay 1000
#define ParkYReverseDelay 500
#define ParkYReversePath 2000



////////// Transporter: //////////
// engine:
#define TransporterEnPin 8
#define TransporterDirPin 3
#define TransporterStepPin 6
// ender:
#define TransporterEnderPin A6
#define TransporterEnderLevel HIGH
#define TransporterEnderAnalogMode true
// reverse
#define TransporterMaxDelay 2000
#define TransporterWorkDelay 500
#define TransporterReverseMaxDelay 2000
#define TransporterReverseDelay 500



////////// Slots: //////////
#define SlotsDirPin 4
// ender:
#define SlotsEnderPin A6
#define SlotsEnderLevel LOW
#define SlotsEnderAnalogMode true
// reverse
#define SlotsMaxDelay 2000
#define SlotsWorkDelay 400
#define SlotsReverseMaxDelay 2000
#define SlotsReverseDelay 500
#define SlotsReversePath 500

///////// Column 0
#define Col0EnPin 8

///////// Row 0
#define Row0StepPin 7

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