#ifndef __CORE__
#define __CORE__

#define POWER_STATE   1
#define INTRO_STATE  2
#define STARTING_STATE 3
#define GAMING_STATE  4
#define CONTINUING_STATE 5
#define GAME_OVER_STATE 6

/* core business logic  */

void initCore();
void power();
void intro();
void starting();
void gaming();
void continuing();
void over();
void checkButtonPressed(int buttonIndex);

#endif