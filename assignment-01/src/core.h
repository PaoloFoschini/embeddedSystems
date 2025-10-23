#ifndef __CORE__
#define __CORE__

#define POWER_STATE   1
#define INTRO_STATE  2
#define GAMING_STATE  3
#define SHOW_STATE 4
#define GAMEOVER_STATE 5 

/* core business logic  */

void initCore();
void power();
void intro();
void gaming();
void show();
void over();

#endif