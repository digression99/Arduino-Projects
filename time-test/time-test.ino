#include "Time_Setting.h"
#include "Led_Display.h"
#include "Led_Display_Data.h"

unsigned long previousMillis = 0;
const int INTERVAL = 1000;

// display control variables.
const int DISPLAY_DIN_PIN = 12;
const int DISPLAY_CLK_PIN = 11;
const int DISPLAY_CS_PIN = 10;
const int DISPLAY_N_DEVICES = 4;
LedControl lc = LedControl(DISPLAY_DIN_PIN, DISPLAY_CLK_PIN, DISPLAY_CS_PIN, DISPLAY_N_DEVICES);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  init_display();
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= INTERVAL) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    String strTime = millisToTime(previousMillis);
    
    Serial.println(millisToTime(previousMillis));
    displayTime(strTime);
  }
}
