#include "config.h"
#include "input.h"
#include "output.h"
#include "core.h"
#include "kernel.h"

int difficulty=0;
int round=0;
unsigned int score=0;

void setup()
{   
  initInput();
  initOutput();
  initKernel();
  initCore();  
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
  case STARTING_STATE:
    starting();
  break;
  case CONTINUING_STATE:
    continuing();
  break;
  case GAME_OVER_STATE:
    over();
    break;
  }
  delay(GAME_TICK);
}
