#include "led_function.h"
#include "LedControl.h"

// led display datas

unsigned long delayTime = 100000; // Delay between Frames
unsigned long nowDelay = 0;
byte displayState = LOW;

const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;

void setup()
{

  // button setting
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, RISING); 
  nowDelay = 0;
}

void blink() {
  state = !state;
}

void delayVader() {
  if (++nowDelay >= delayTime) {
    
    if (displayState == LOW) {
      
      sinvader1a();
//  delay(delayTime);
      sinvader2a();
    //  delay(delayTime);
      sinvader3a();
    //  delay(delayTime);
      sinvader4a();
//  delay(delayTime);
      
    } else {
      
  // Put #2 frame on both Display
  sinvader1b();
//  delay(delayTime);
  sinvader2b();
//  delay(delayTime);
  sinvader3b();
//  delay(delayTime);
  sinvader4b();
//  delay(delayTime);
    
    }
    
    nowDelay = 0;
    displayState = !displayState;
  }
}


void loop()
{
  digitalWrite(ledPin, state);
  delayVader();
}
