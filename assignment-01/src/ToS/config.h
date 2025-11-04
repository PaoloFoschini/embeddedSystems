/*  Foschini Paolo    0001122840
*   Pertegato Marco   0001123050
*   Sargov Valerii    0001124110
*/
#ifndef __CONFIG__
#define __CONFIG__

#define N_LEDS 4
#define L1_PIN 7
#define L2_PIN 8
#define L3_PIN 9
#define L4_PIN 10

#define LS_PIN 11

#define N_BUT 4
#define B1_PIN 6
#define B2_PIN 5
#define B3_PIN 4
#define B4_PIN 3

#define POT_PIN A0

#define T1 10000    //Initial Time
#define FX  250     //Time Factor Reduction (regulated by POT value based on 4 difficulties)

#define IDLE_TIME 10000             //Time that system waits before going in deepsleep
#define GAME_OVER_DURATION 10000    //Time that system waits before resetting after GameOver
#define DISPLAYING_TIME 3000        //Time where LCD is showing some messages during transition states
#define LS_DURATION 2000            //Duration of LS LED in GameOver
#define GAME_TICK 50                //Refresh Tick of the Game

#endif
