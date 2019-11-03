////////// LEDs: //////////
// LED00
#define LedNum 8
#define LedPin 19


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
#define ParkYMaxDelay 200
#define ParkYWorkDelay 5
#define ParkYReverseMaxDelay 200
#define ParkYReverseDelay 5
#define ParkYReversePath 500



////////// Transporter: //////////
// engine:
#define TransporterEnPin A2
#define TransporterDirPin A7
#define TransporterStepPin A6
// ender:
#define TransporterEnderPin 18
#define TransporterEnderLevel HIGH
#define TransporterEnderAnalogMode false
// reverse
#define TransporterMaxDelay 1000
#define TransporterWorkDelay 400
#define TransporterReverseMaxDelay 1000
#define TransporterReverseDelay 400



////////// Slots: //////////
#define SlotsDirPin 41
#define LED_PIN 3

// ender:
#define SlotsEnderPin 3
#define SlotsEnderLevel HIGH
#define SlotsEnderAnalogMode false
// reverse
#define SlotsMaxDelay 400
#define SlotsWorkDelay 200
#define SlotsReverseMaxDelay 400
#define SlotsReverseDelay 200
#define SlotsReversePath 8000

///////// Slot 00
#define Slot00EnPin A8
#define Slot00StepPin 46
#define Slot00DirPin 48
#define LED00 0

///////// Slot 01
#define Slot01EnPin 24
#define Slot01StepPin 26
#define Slot01DirPin 28
#define LED01 2

///////// Slot 02
#define Slot02EnPin 30
#define Slot02StepPin 36
#define Slot02DirPin 34
#define LED02 4


///////// masterTerminal /////////
#define baudRate 9600
#define PARK_Y 1
#define UNLOAD_SLOT00 2
#define TOGGLE_GREEN00 3
#define IS_DOOR_CLOSED 4
#define CLOSE_THE_DOOR 5
#define OPEN_THE_DOOR 6