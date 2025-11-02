#ifndef __INPUT__
#define __INPUT__

void initInput();
void resetInput();
bool isButtonPressed(int buttoncurrentDigit);
void resetLastPressedButton();
int getLastPressedButton();
int getPotValue();
 
#endif
