#include "Time_Setting.h"

String millisToTime(unsigned long t) {
    int seconds = (t / 1000);
    int minutes = seconds / 60;
    seconds %= 60;
    String strMinutes = (minutes < 10) ? "0" + String(minutes) : String(minutes);
    String strSeconds = (seconds < 10) ? "0" + String(seconds) : String(seconds);
    return strMinutes + strSeconds;
}
