#include <SoftwareSerial.h>
#include "Button.h"

const int interruptPin = 3;

const int bluetoothTx = 12;
const int bluetoothRx = 13;
SoftwareSerial mySerial(bluetoothRx, bluetoothTx);

const int ledPin = 7;
bool state = LOW;

void setup() {
  // bluetooth setup
  attachButton(interruptPin);
  Serial.begin(9600);
  while (!Serial) {
      ; // wait for serial port to connect. Needed for native USB port only
  }
  while (!mySerial) {
      ;
  }
  Serial.println("Goodnight moon!");
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.println("Hello, world?");

}

void loop() {
  // put your main code here, to run repeatedly:
    if (mySerial.available()) {
        Serial.println("my serial available");
//        Serial.println(mySerial.read());
        while (mySerial.available()) Serial.println(mySerial.read());
    }
    if (Serial.available()) {
        Serial.println("serial available");
        while (Serial.available()) {
            char c = Serial.read();
            Serial.println(c);
            mySerial.write(c);
        }
    }
    digitalWrite(ledPin, state);
    if (state) {
        mySerial.write(B11011101);
        Serial.write(B01011011);
    }
}
