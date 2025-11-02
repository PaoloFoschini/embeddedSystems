#include "output.h"
#include <Arduino.h>
#include "config.h"
#include "LiquidCrystal_I2C.h"
#include <Math.h>

#define SDA_PIN SDA
#define SCL_PIN SCL
#define LCD_ADDRESS 0x27
#define LCD_ROWS 2
#define LCD_COLS 16

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

void resetFading(){
  fadeAmount = 5;
  currIntensity = 0;
  analogWrite(LS_PIN, currIntensity); 
}

void turnOffLCD(){
  lcd.noDisplay();
  lcd.noBacklight();
}

void turnOnLCD(){
  lcd.display();
  lcd.backlight();
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
    int newlinecurrentDigit = text.indexOf('\n');
    String riga1;
    String riga2 = "";

    if (newlinecurrentDigit == -1) {
        riga1 = text.substring(0, min(text.length(), LCD_COLS));
    } else {
        riga1 = text.substring(0, newlinecurrentDigit);
        riga1 = riga1.substring(0, min(riga1.length(), LCD_COLS));
        if (newlinecurrentDigit + 1 < text.length()) {
            riga2 = text.substring(newlinecurrentDigit + 1);
            riga2 = riga2.substring(0, min(riga2.length(), LCD_COLS));
        }
    }
    lcd.setCursor(0, 0); 
    lcd.print(riga1);
    lcd.setCursor(0, 1);
    lcd.print(riga2);
}