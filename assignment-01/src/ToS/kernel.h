/*  Foschini Paolo    0001122840
*   Pertegato Marco   0001123050
*   Sargov Valerii    0001124110
*/
#ifndef __KERNEL__
#define __KERNEL__

#include <Arduino.h> 

/* general state management procedure */

void initKernel();
void updateStateTime();
void changeState(int new_state);

int getCurrentState();
long getCurrentTimeInState();
long getEnteredStateTime();
bool isJustEnteredInState(); 

#endif