#include "Time_Setting.h"

String millisToTime(unsigned long t) {
    int seconds = (t / 1000);
    int minutes = seconds / 60;

    seconds %= 60;
//    int seconds = (t / 1000) % 60;
//    int minutes = (t / (1000 * 60)) % 60;
//    int hours = (t/(1000*60*60))%24;
    
//    String strHours = (hours < 10) ? "0" + String(hours) : String(hours);
    String strMinutes = (minutes < 10) ? "0" + String(minutes) : String(minutes);
    String strSeconds = (seconds < 10) ? "0" + String(seconds) : String(seconds);

//    return strHours + ":" + strMinutes + ":" + strSeconds;
    return strMinutes + strSeconds;
}
