/*  Foschini Paolo    0001122840
*   Pertegato Marco   0001123050
*   Sargov Valerii    0001124110
*/
#ifndef __INPUT__
#define __INPUT__

void initInput();
void resetInput();
bool isButtonPressed(int buttoncurrentDigit);
void resetLastPressedButton();
int getLastPressedButton();
int getPotValue();
void detachHandler();
void attachHandler();
void disableAll();
void reEnableAll();
void wakeUp();
 
#endif
