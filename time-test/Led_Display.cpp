#include "Led_Display.h"

extern LedControl lc;
extern byte chars[38][8];

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

void displayOneChar(int device, char c) {
    int idx = int(c - '0');
    Serial.println(idx);
    for (int i = 0; i < 8; ++i) {
        lc.setRow(device, i, (byte)chars[idx][i]);
    }
}

void displayTime(String timeStr) {
    int l = timeStr.length();
//    Serial.print("length : ");
//    Serial.println(l);
//    Serial.print("display time : ");
    for (int i = 0; i < l; ++i) {
        displayOneChar(3 - i, timeStr.charAt(i));
    }
//    char timeCharArr[5] = { 0, };
//    timeStr.toCharArray(timeCharArr, timeStr.length());
//    Serial.print("TimeCharArr : ");
//    Serial.println(timeCharArr);
//    for (int i = 3; i >= 0; --i) {
//        displayOneChar(i, timeCharArr[i]);
//    }
}
