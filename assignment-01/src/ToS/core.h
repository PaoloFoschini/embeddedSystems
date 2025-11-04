/*  Foschini Paolo    0001122840
*   Pertegato Marco   0001123050
*   Sargov Valerii    0001124110
*/
#ifndef __CORE__
#define __CORE__

#define SLEEP_STATE   1
#define INITIAL_STATE  2
#define STARTING_STATE 3
#define GAMING_STATE  4
#define END_ROUND_STATE 5
#define GAME_OVER_STATE 6

/* core business logic  */

void initCore();
void sleeping();
void initializing();
void starting();
void gaming();
void endingRound();
void over();
void checkCorrectSequence(int buttoncurrentDigit);

#endif