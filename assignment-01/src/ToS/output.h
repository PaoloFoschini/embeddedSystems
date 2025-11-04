/*  Foschini Paolo    0001122840
*   Pertegato Marco   0001123050
*   Sargov Valerii    0001124110
*/
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
