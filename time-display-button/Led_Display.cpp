#include "Led_Display.h"

extern LedControl lc;
extern byte chars[38][8];
extern const int DISPLAY_N_DEVICES;
extern const int DISPLAY_INTENSITY;

void init_display() {
    for (int i = 0; i < DISPLAY_N_DEVICES; ++i) {
        lc.shutdown(i, false);
        lc.setIntensity(i, DISPLAY_INTENSITY);
        lc.clearDisplay(i);
    }
}

void displayOneChar(int device, char c) {
    int idx = 0;
    if (c >= '0' && c <= '9') idx = int(c - '0');
    else idx = int(c - 'A') + 10; // only upper case
    for (int i = 0; i < 8; ++i) {
        lc.setRow(device, i, (byte)chars[idx][i]);
    }
}

void displayText(String str) {
    int l = str.length();
    for (int i = 0; (i < l) && (DISPLAY_N_DEVICES - i - 1 >= 0); ++i) {
        displayOneChar(DISPLAY_N_DEVICES - i - 1, str.charAt(i));
    }
}
