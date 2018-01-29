#include "Button.h"
#include "Led_Display.h"
#include "Led_Data.h"
#include <SoftwareSerial.h>

bool state = LOW;
const int ledPin = 7;
const int interruptPin = 3;

// display control variables.
const int DISPLAY_DIN_PIN = 12;
const int DISPLAY_CLK_PIN = 11;
const int DISPLAY_CS_PIN = 10;
const int DISPLAY_N_DEVICES = 4;
LedControl lc = LedControl(DISPLAY_DIN_PIN, DISPLAY_CLK_PIN, DISPLAY_CS_PIN, DISPLAY_N_DEVICES);
unsigned long delayTime = 100000; // Delay between Frames
unsigned long nowDelay = 0;
byte displayState = LOW;

// bluetooth variables.
const int bluetoothTx = 12;
const int bluetoothRx = 13;
SoftwareSerial mySerial(bluetoothTx, bluetoothRx);

void delayDisplay() {
    if (++nowDelay >= delayTime) {
        
        if (displayState == LOW) {
            sinvader1a();
            sinvader2a();
            sinvader3a();
            sinvader4a();
        } else {
            // Put #2 frame on both Display
            sinvader1b();
            sinvader2b();
            sinvader3b();
            sinvader4b();
            
        }
        nowDelay = 0;
        displayState = !displayState;
    }
}

void controlDisplay() {
    if (state) {
        sinvader1a();
        sinvader2a();
        sinvader3a();
        sinvader4a();
    } else {
        sinvader1b();
        sinvader2b();
        sinvader3b();
        sinvader4b();
    }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  attachButton(interruptPin);
  init_display();

  // bluetooth setup
  Serial.begin(57600);
  while (!Serial) {
      ; // wait for serial port to connect. Needed for native USB port only
  }
  while (!mySerial) {
      ;
  }
  Serial.println("Goodnight moon!");
  // set the data rate for the SoftwareSerial port
  mySerial.begin(4800);
  mySerial.println("Hello, world?");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, state);
  controlDisplay();

  if (mySerial.available()) {
        Serial.println("my serial available");
        Serial.println(mySerial.read());
//        Serial.write((byte)mySerial.read());
    }
    if (Serial.available()) {
        Serial.println("serial available");
        Serial.println((char)Serial.read());
//        Serial.println(bytesSent);
//        mySerial.write((byte)Serial.read());
    }
}
