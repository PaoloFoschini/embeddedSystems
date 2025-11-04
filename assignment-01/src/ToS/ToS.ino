/*  Foschini Paolo    0001122840
*   Pertegato Marco   0001123050
*   Sargov Valerii    0001124110
*/
#include "config.h"
#include "input.h"
#include "output.h"
#include "core.h"
#include "kernel.h"

void setup()
{   
  initInput();
  initOutput();
  initCore();  
  changeState(INITIAL_STATE);
}

void loop()
{
  updateStateTime();
  switch (getCurrentState()) {
  case SLEEP_STATE:
    sleeping();
    break; 
  case INITIAL_STATE:
    initializing();
    break;
  case STARTING_STATE:
    starting();
    break;
  case GAMING_STATE:
    gaming();
    break;  
  case END_ROUND_STATE:
    endingRound();
    break;
  case GAME_OVER_STATE:
    over();
    break;
  }
  delay(GAME_TICK);
}
