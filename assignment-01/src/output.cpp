#include "output.h"
#include "Arduino.h"
#include "config.h"
#include "LiquidCrystal_I2C.h"

// #define __DEBUG__

uint8_t outputPins[N_LEDS] = {L1_PIN,L2_PIN,L3_PIN, L4_PIN};

int fadeAmount = 5;
int currIntensity = 0;
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(LCD_ADDRESS,LCD_COLS,LCD_ROWS);

void initOutput(){
  for (int i = 0; i < N_LEDS; i++) {
    pinMode(outputPins[i], OUTPUT);      
  }
  pinMode(LS_PIN, OUTPUT);
  lcd.init();
  lcd.backlight();  
}
void resetOutput(){
  resetOutputLeds();
  digitalWrite(LS_PIN,LOW);
  lcd.clear();
}

void resetOutputLeds(){
  for (int i = 0; i < N_LEDS; i++) {
    digitalWrite(outputPins[i], LOW);      
  }
}

void turnOnLed(int button_number){
  digitalWrite(outputPins[button_number], HIGH);
}

void keepControlLedFading(int intensity){
  analogWrite(LS_PIN, intensity);
  currIntensity = currIntensity + fadeAmount;
   if (currIntensity == 0 || currIntensity == 255) {
    fadeAmount = -fadeAmount ; 
   } 
   //delay(20); da fare da parte del chiamante
}

void setText(String text) {
    
    // 1. Pulisci il display per sicurezza
    lcd.clear(); 

    // 2. Controlla se la stringa è più lunga della prima riga
    if (text.length() <= LCD_COLS) {
        
        // La stringa entra tutta nella prima riga
        lcd.setCursor(0, 0); // Riga 1, Colonna 1
        lcd.print(text);
        
    } else {
        
        // La stringa è troppo lunga: spezzala.
        
        // Parte 1 (Prima riga): Primi LCD_COLS caratteri
        String riga1 = text.substring(0, LCD_COLS); 
        
        // Parte 2 (Seconda riga): Dal carattere LCD_COLS in poi
        // Prendiamo al massimo altri LCD_COLS caratteri per non eccedere la 2a riga
        String riga2 = text.substring(LCD_COLS, LCD_COLS * 2); 

        // Stampa la prima riga
        lcd.setCursor(0, 0); // Riga 1
        lcd.print(riga1);
        
        // Stampa la seconda riga
        lcd.setCursor(0, 1); // Riga 2
        lcd.print(riga2);
    }
}
