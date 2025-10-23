#include "config.h"
#include "input.h"
#include "output.h"

void setup()
{ 
  initInput();
  initOutput();
  changeState(INTRO_STATE);
}

void loop()
{
  updateStateTime();
  switch (getCurrentState()) {
  case POWER_STATE:
    power();
    break; 
  case INTRO_STATE:
    intro();
    break;
  case GAMING_STATE:
    gaming();
    break;
  case SHOWING_STATE: //? Forse ?
    show();
    break;
  case GAME_OVER_STATE:
    over();
    break;
  } 
}
