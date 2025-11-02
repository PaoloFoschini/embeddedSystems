#ifndef __OUTPUT__
#define __OUTPUT__

#include <Arduino.h>

void initOutput();
void resetOutput();
void resetOutputLeds();
void turnOffLCD();
void turnOnLCD();
void resetFading();
void turnOnLed(int button_number);
void keepControlLedFading();
void setText(String text);

#endif
