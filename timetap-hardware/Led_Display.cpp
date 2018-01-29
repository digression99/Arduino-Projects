
#include "Led_Display.h"

extern LedControl lc;
extern byte invader1a[], invader1b[], invader2a[], invader2b[];

void init_display() {
    lc.shutdown(0, false); // Wake up displays
    lc.shutdown(1, false);
    lc.shutdown(2, false);
    lc.shutdown(3, false);
    // up to 4 devices
    
    lc.setIntensity(0, 5); // Set intensity levels
    lc.setIntensity(1, 5);
    lc.setIntensity(2, 5);
    lc.setIntensity(3, 5);
    
    lc.clearDisplay(0);  // Clear Displays
    lc.clearDisplay(1);
    lc.clearDisplay(2);
    lc.clearDisplay(3);
}

//  Take values in Arrays and Display them
void sinvader1a()
{
    for (int i = 0; i < 8; i++)
    {
        lc.setRow(0, i, invader1a[i]);
    }
}

void sinvader1b()
{
    for (int i = 0; i < 8; i++)
    {
        lc.setRow(0, i, invader1b[i]);
    }
}

void sinvader2a()
{
    for (int i = 0; i < 8; i++)
    {
        lc.setRow(1, i, invader2a[i]);
    }
}

void sinvader2b()
{
    for (int i = 0; i < 8; i++)
    {
        lc.setRow(1, i, invader2b[i]);
    }
}

void sinvader3a()
{
    for (int i = 0; i < 8; i++)
    {
        lc.setRow(2, i, invader1a[i]);
    }
}

void sinvader3b()
{
    for (int i = 0; i < 8; i++)
    {
        lc.setRow(2, i, invader1b[i]);
    }
}

void sinvader4a()
{
    for (int i = 0; i < 8; i++)
    {
        lc.setRow(3, i, invader1a[i]);
    }
}

void sinvader4b()
{
    for (int i = 0; i < 8; i++)
    {
        lc.setRow(3, i, invader1b[i]);
    }
}
