#ifndef __CONFIG__
#define __CONFIG__

// #define __DEBUG__

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

#define T1 10000 //Tempo iniziale
#define FX  250 //Riduzione Tempo per Round (regolata dal potenziometro su un base di 4 difficoltà)

#define IDLE_TIME 10000 //Tempo dopo il quale va in deepsleep
#define GAME_OVER_DURATION 10000 //Tempo dopo il quale va in deepsleep
#define DISPLAYING_TIME 3000 //Time where LCD is showing some messages during transition states
#define LS_DURATION 2000 //Tempo di accensione di LS
#define GAME_TICK 50

#endif
