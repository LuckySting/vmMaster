#include <Arduino.h>
#include "vmCore.h"
#include "transporter.h"
#include "parkY.h"
#include "toLevel2.h"
#include "toLevel3.h"
#include "slot.h"
#include "masterTerminal.h"
#include "FastLED.h"
#include "Led.h"

Flag ParkYflag;
Flag Transport;
Flag Slot;
Flag to1Lvl;
Flag to2Lvl;
Flag to3Lvl;

Flag MinY;
Flag Lazer;
Flag LazerR;
TriggerTask enderLazer(&Lazer, TransporterEnderPin, TransporterEnderLevel, TransporterEnderAnalogMode);
TriggerTask enderLazerR(&LazerR, SlotsEnderPin, SlotsEnderLevel, SlotsEnderAnalogMode);
TriggerTask enderMinY(&MinY, ParkYEnderPin, ParkYEnderLevel, ParkYEnderAnalogMode);

masterTerminal masTer;
Flag Ok;
Flag Oops;
SerialTask ok(0x0);
SerialTask oops(0x1);

Flag Block;

Led led;
CRGB leds[LedNum];

void masterTerminal::closeTheDoor(){
  Ok.set(HIGH);
}
void masterTerminal::isDoorClosed(){
  Ok.set(HIGH);
}
void masterTerminal::openTheDoor(){
  Ok.set(HIGH);
}

bool o=true;

void masterTerminal::toggleGreen(uint8_t slotCode){
  switch (slotCode)
  {
  case 0x00:
    led.greenOn(LED00, leds);
    delay(200);
    break;

  case 0x01:
    led.greenOn(LED01, leds);
    delay(200);
    break;

  case 0x02:
    led.greenOn(LED02, leds);
    delay(200);
    break;
  
  case 0x03:
    led.greenOn(LED03, leds);
    delay(200);
    break;

  case 0x10:
    led.greenOn(LED10, leds);
    delay(200);
    break;

  case 0x11:
    led.greenOn(LED11, leds);
    delay(200);
    break;

  case 0x12:
    led.greenOn(LED12, leds);
    delay(200);
    break;
  
  case 0x13:
    led.greenOn(LED13, leds);
    delay(200);
    break;

  case 0x20:
    led.greenOn(LED20, leds);
    delay(200);
    break;

  case 0x21:
    led.greenOn(LED21, leds);
    delay(200);
    break;

  case 0x22:
    led.greenOn(LED22, leds);
    delay(200);
    break;
  
  case 0x23:
    led.greenOn(LED23, leds);
    delay(200);
    break;
  
  default:
    led.off(leds);
    delay(200);
    break;
  }
  Ok.set(HIGH);
}
void masterTerminal::toggleRed(uint8_t slotCode){
  Ok.set(HIGH);
}
void masterTerminal::getItem(uint8_t slotCode){
  Block.set(HIGH);
  switch (slotCode)
  {
  case 0x00:
    slotE.switchDrive(Slot00EnPin, Slot00StepPin, Slot00DirPin);
    to1Lvl.set(HIGH);
    break;

  case 0x01:
    slotE.switchDrive(Slot01EnPin, Slot01StepPin, Slot01DirPin);
    to1Lvl.set(HIGH);
    break;

  case 0x02:
    slotE.switchDrive(Slot02EnPin, Slot02StepPin, Slot02DirPin);
    to1Lvl.set(HIGH);
    break;
  
  case 0x03:
    slotE.switchDrive(Slot03EnPin, Slot03StepPin, Slot03DirPin);
    to1Lvl.set(HIGH);
    break;

  case 0x10:
    slotE.switchDrive(Slot10EnPin, Slot10StepPin, Slot10DirPin);
    to2Lvl.set(HIGH);
    break;

  case 0x11:
    slotE.switchDrive(Slot11EnPin, Slot11StepPin, Slot11DirPin);
    to2Lvl.set(HIGH);
    break;

  case 0x12:
    slotE.switchDrive(Slot12EnPin, Slot12StepPin, Slot12DirPin);
    to2Lvl.set(HIGH);
    break;
  
  case 0x13:
    slotE.switchDrive(Slot13EnPin, Slot13StepPin, Slot13DirPin);
    to2Lvl.set(HIGH);
    break;

  case 0x20:
    slotE.switchDrive(Slot20EnPin, Slot20StepPin, Slot20DirPin);
    to3Lvl.set(HIGH);
    break;

  case 0x21:
    slotE.switchDrive(Slot21EnPin, Slot21StepPin, Slot21DirPin);
    to3Lvl.set(HIGH);
    break;

  case 0x22:
    slotE.switchDrive(Slot22EnPin, Slot22StepPin, Slot22DirPin);
    to3Lvl.set(HIGH);
    break;
  
  case 0x23:
    slotE.switchDrive(Slot23EnPin, Slot23StepPin, Slot23DirPin);
    to3Lvl.set(HIGH);
    break;

  default:
    break;
  }
}

void setup() {
  FastLED.addLeds<WS2811, LedPin, GRB>(leds, LedNum).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(255);
  pinMode(LedPin, OUTPUT);
  parkYInit(&MinY);
  transporterInit(&Lazer);
  slotInit(&LazerR);
  toLevel2Init();
  toLevel3Init();
  ParkYflag.set(HIGH);
  Block.set(HIGH);
  Transport.set(LOW);
  to2Lvl.set(LOW);
  to3Lvl.set(LOW);
  Slot.set(LOW);
  Ok.set(LOW);
  Oops.set(LOW);
  Serial.begin(baudRate);
  led.off(leds);
  delay(200);
}

void loop() {
  while(true){
    if(Ok.get()){
    if(ok.update()){
      Ok.set(LOW);
    }
  }

  if(Oops.get()){
    if(oops.update()){
      Oops.set(LOW);
    }
  }


  if(!Block.get()){
    masTer.check();
  }

  // if(Serial.available() == 1){
  //   uint8_t cmd = Serial.read();
  //   if(cmd == 49){
  //     led.greenOn(LED00, leds);
  //   }
  //   if(cmd == 50){
  //     led.greenOn(LED01, leds);
  //   }
  //   if(cmd == 51){
  //     led.greenOn(LED02, leds);
  //   }
  //   if(cmd == 52){
  //     led.greenOn(6, leds);
  //   }
  // }

  if(ParkYflag.get()){
    enderMinY.update();
    if(parkY.update()){
      parkY.stop();
      ParkYflag.set(LOW);
      Block.set(LOW);
      // to3Lvl.set(HIGH);
    }
  }


  if(Transport.get()){
    enderLazer.update();
    if(transporter.update()){
      transporter.stop();
      Transport.set(LOW);
      Ok.set(HIGH);
    }
  }

  if(Slot.get()){
    enderLazerR.update();
    if(slot.update()){
      slot.stop();
      Slot.set(LOW);
      Transport.set(HIGH);
      ParkYflag.set(HIGH);
    }
  }

  if(to1Lvl.get()){
    to1Lvl.set(LOW);
    Slot.set(HIGH);
  }

  if(to2Lvl.get()){
    if(ToLevel2.update()){
       to2Lvl.set(LOW);
       Slot.set(HIGH);
    }
  }

  if(to3Lvl.get()){
    if(ToLevel3.update()){
       to3Lvl.set(LOW);
       Slot.set(HIGH);
    }
  }
  }

}

// #include <Arduino.h>
// #include "conf.h"
// #include "FastLED.h"
// #include "Led.h"
// Led led;
// CRGB leds[LedNum];
// void setup() {

// }
// void loop() {
//   led.greenOn(0, leds);
//   delay(1000);
//   led.redOn(0, leds);
//   delay(1000);
// }