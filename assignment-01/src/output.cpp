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

void keepControlLedFading(){
  analogWrite(LS_PIN, currIntensity);
  currIntensity = currIntensity + fadeAmount;
   if (currIntensity == 0 || currIntensity == 255) {
    fadeAmount = -fadeAmount ; 
   } 
}

void setText(String text) {

    lcd.clear();
    int newlineIndex = text.indexOf('\n');
    String riga1;
    String riga2 = ""; // Inizializza a vuoto per sicurezza

    if (newlineIndex == -1) {
        riga1 = text.substring(0, Math.min(text.length(), LCD_COLS));
    } else {
        riga1 = text.substring(0, newlineIndex);
        riga1 = riga1.substring(0, Math.min(riga1.length(), LCD_COLS));
        if (newlineIndex + 1 < text.length()) {
            riga2 = text.substring(newlineIndex + 1);
            riga2 = riga2.substring(0, Math.min(riga2.length(), LCD_COLS));
        }
    }
    lcd.setCursor(0, 0); 
    lcd.print(riga1);
    if (!riga2.isEmpty()) {
        lcd.setCursor(0, 1)
        lcd.print(riga2);
    }
}