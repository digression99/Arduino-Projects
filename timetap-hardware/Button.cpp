#include "Button.h"

extern bool state;
extern SoftwareSerial mySerial;

void blinkLed() {
    state = !state;
}

void writeToBluetooth() {
    Serial.println('a');
    mySerial.println((byte)'b');
}

void attachButton(int interruptPin) {
//    attachInterrupt(digitalPinToInterrupt(interruptPin), blinkLed, RISING);
    attachInterrupt(digitalPinToInterrupt(interruptPin), writeToBluetooth, RISING);
}

