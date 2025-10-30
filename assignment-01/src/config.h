#ifndef __CONFIG__
#define __CONFIG__

// #definge __DEBUG__

#define N_LEDS 4
#define L1_PIN 8
#define L2_PIN 9
#define L3_PIN 10
#define L4_PIN 12

#define LS_PIN 11

#define N_BUT 4
#define B1_PIN 6
#define B2_PIN 5
#define B3_PIN 4
#define B4_PIN 3

#define POT_PIN A0

#define SDA_PIN SDA
#define SCL_PIN SCL
#define LCD_ADDRESS 0x27
#define LCD_ROWS 2
#define LCD_COLS 16

#define GAME_TICK 1000
#define FADE_AMOUNT 5

#define T1 10000 //Tempo iniziale
#define FX  125 //Riduzione Tempo per Round (regolata dal potenziometro su un base di 4 difficoltà)

#define IDLE_TIME 10000 //Tempo dopo il quale va in deepsleep
#define CONTINUE_TIME 3000
#define GO_TIME 2000
#define GAME_OVER_DURATION 2000 //Tempo di accensione di LS

#endif
