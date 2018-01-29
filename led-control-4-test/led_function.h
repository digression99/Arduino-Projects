#include "Arduino.h"
#include "led_data.h"
#include "LedControl.h"

LedControl lc = LedControl(12, 11, 10, 4); // Pins: DIN,CLK,CS, # of Display connected

void init_display();

void sinvader1a();
void sinvader1b();

void sinvader2a();
void sinvader2b();

void sinvader3a();
void sinvader3b();

void sinvader4a();
void sinvader4b();

