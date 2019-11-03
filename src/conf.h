////////// LEDs: //////////
// LED00
#define LedNum 24
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

///////// Slot 03
#define Slot03EnPin 30
#define Slot03StepPin 36
#define Slot03DirPin 34
#define LED03 6

///////// Slot 10
#define Slot10EnPin A8
#define Slot10StepPin 46
#define Slot10DirPin 48
#define LED10 14

///////// Slot 11
#define Slot11EnPin 24
#define Slot11StepPin 26
#define Slot11DirPin 28
#define LED11 12

///////// Slot 12
#define Slot12EnPin 30
#define Slot12StepPin 36
#define Slot12DirPin 34
#define LED12 10

///////// Slot 13
#define Slot13EnPin 30
#define Slot13StepPin 36
#define Slot13DirPin 34
#define LED13 8

///////// Slot 20
#define Slot20EnPin A8
#define Slot20StepPin 46
#define Slot20DirPin 48
#define LED20 16

///////// Slot 21
#define Slot21EnPin 24
#define Slot21StepPin 26
#define Slot21DirPin 28
#define LED21 18

///////// Slot 22
#define Slot22EnPin 30
#define Slot22StepPin 36
#define Slot22DirPin 34
#define LED22 20

///////// Slot 23
#define Slot23EnPin 30
#define Slot23StepPin 36
#define Slot23DirPin 34
#define LED23 22


///////// masterTerminal /////////
#define baudRate 9600