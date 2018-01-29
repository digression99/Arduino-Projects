#include "Arduino.h"
#include "LedControl.h"

void init_display();

void displayTime(String timeStr);
void displayOneChar(int device, char c);
