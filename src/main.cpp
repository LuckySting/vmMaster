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
  switch (slotCode)
  {
  case 0x00:
    slotE.switchDrive(Slot00EnPin, Slot00StepPin, Slot00DirPin);
    to2Lvl.set(HIGH);
    break;

  case 0x01:
    slotE.switchDrive(Slot01EnPin, Slot01StepPin, Slot01DirPin);
    to1Lvl.set(HIGH);
    break;

  case 0x02:
    slotE.switchDrive(Slot02EnPin, Slot02StepPin, Slot02DirPin);
    to1Lvl.set(HIGH);
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
  Serial.begin(9600);
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