#include "input.h"
#include "config.h"
#include <Arduino.h>
#include <EnableInterrupt.h>

#define BOUNCING_TIME 50

// #define __DEBUG__

uint8_t inputPins[N_BUT] = {B1_PIN, B2_PIN, B3_PIN, B4_PIN}; //All Button PINS
bool buttonPressed[N_BUT] = {false, false, false, false}; //Array to avoid multiple press if hold pressed Button
int lastButtonPressed = -1;

long lastButtonPressedTimestamps[N_BUT];

void buttonHandler(int i);
void buttonHandler0(){ buttonHandler(0); }
void buttonHandler1(){ buttonHandler(1); }
void buttonHandler2(){ buttonHandler(2); }
void buttonHandler3(){ buttonHandler(3); }

void (*buttonHandlers[N_BUT])() = { buttonHandler0, buttonHandler1, buttonHandler2, buttonHandler3 };

void buttonHandler(int i){
  long ts = millis();
  if (ts - lastButtonPressedTimestamps[i] > BOUNCING_TIME){
    lastButtonPressedTimestamps[i] = ts;
    int status = digitalRead(inputPins[i]);
    if (status == HIGH && !buttonPressed[i]) { 
        buttonPressed[i] = true;
        lastButtonPressed = i;        
    }
  }
}

void initInput(){
  for (int i = 0; i < N_BUT; i++) {
    pinMode(inputPins[i], INPUT);  
    enableInterrupt(inputPins[i], buttonHandlers[i], CHANGE);       
  }
}

void resetInput(){
  long ts = millis();
  for (int i = 0; i < N_BUT; i++) {
    buttonPressed[i] = false;      
    lastButtonPressedTimestamps[i] = ts;    
  }
  resetLastPressedButton();
}

bool isButtonPressed(int buttoncurrentDigit){
  return buttonPressed[buttoncurrentDigit];
}

void resetLastPressedButton(){
  lastButtonPressed = -1;
}

int getLastPressedButton(){
  return lastButtonPressed;
}


int getPotValue(){
  return analogRead(POT_PIN);
}

void disableAll(){
  for (int i = 0; i < N_BUT; i++) {
    disableInterrupt(inputPins[i]);       
  }
}

void reEnableAll(){
  for (int i = 0; i < N_BUT; i++) {
    enableInterrupt(inputPins[i], buttonHandlers[i], CHANGE);       
  }
}

void detachHandler(){
  disableAll();
  enableInterrupt(inputPins[0], wakeUp, RISING);
}

void attachHandler(){
  disableInterrupt(inputPins[0]);
  reEnableAll();
}

void wakeUp(){}

