#ifndef __CONFIG__

#define __CONFIG__

#define N_LEDS 4
#define L1_PIN 8
#define L2_PIN 9
#define L3_PIN 10
#define L4_PIN 11

#define LS_PIN 12

#define B1_PIN 6
#define B2_PIN 5
#define B3_PIN 4
#define B4_PIN 3

#define POT_PIN A0

#define LCD1_PIN A5
#define LCD2_PIN A6

#define T1 5000 //Tempo iniziale
#define F  250 //Riduzione Tempo per Round (regolata dal potenziometro su un base di 4 difficoltà)

#define IDLE_TIME 10000 //Tempo dopo il quale va in deepsleep
#define GAME_OVER_DURATION 2000 //Tempo di accensione di LS

#endif