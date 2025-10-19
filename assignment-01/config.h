#ifndef __CONFIG__

#define __CONFIG__

#define L1_PIN 11
#define L2_PIN 11
#define L3_PIN 11
#define L4_PIN 11
#define LS_PIN 11

#define B1_PIN 11
#define B2_PIN 11
#define B3_PIN 11
#define B4_PIN 11

#define POT_PIN A0

#define LCD1_PIN A5
#define LCD2_PIN A6

#define T1 //Tempo iniziale
#define F  //Riduzione Tempo per Round (regolata dal potenziometro su un base di 4 difficoltà)

#define IDLE_TIME 10000 //Tempo dopo il quale va in deepsleep
#define GAME_OVER_DURATION 2000 //Tempo di accensione di LS

#endif