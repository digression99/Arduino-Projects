#include "Time_Setting.h"
#include "Led_Display_Data.h"
#include "Led_Display.h"

// time control variables.
unsigned long previousMillis = 0;
const int INTERVAL = 1000;

// display control variables.
const int DISPLAY_DIN_PIN = 12;
const int DISPLAY_CLK_PIN = 11;
const int DISPLAY_CS_PIN = 10;
const int DISPLAY_N_DEVICES = 4;
const int DISPLAY_INTENSITY = 5;
LedControl lc = LedControl(DISPLAY_DIN_PIN, DISPLAY_CLK_PIN, DISPLAY_CS_PIN, DISPLAY_N_DEVICES);

void setup() {
  // serial setting
  Serial.begin(9600);
  // display setting
  init_display();
}

void loop() {
  // put your main code here, to run repeatedly:

}
