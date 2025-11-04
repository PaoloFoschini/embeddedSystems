#include "core.h"
#include "config.h"
#include <Arduino.h>
#include "kernel.h"
#include "input.h"
#include "output.h"
#include <Math.h>
#include <avr/sleep.h>

unsigned int difficulty;
unsigned int score;
int sequenceNumbers[N_LEDS] = {0, 1, 2, 3};
int currentDigit;
int pressedButton;

void initCore(){
    Serial.begin(9600);
    pressedButton=-1;
    difficulty = 0;
    score = 0;
    currentDigit = 0;
}

void sleeping(){
    Serial.println("GOING IN POWER DOWN IN 1s ...");
    Serial.flush();
    delay(1000);
    detachHandler();
    turnOffLCD();
    resetFading();
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);  
    sleep_enable();
    sleep_mode();    
    sleep_disable();   
    Serial.println("WAKE UP");
    attachHandler();
    turnOnLCD();
    changeState(INITIAL_STATE);
}

void initializing(){ 
    if (isJustEnteredInState())
    {
        //Should be:"Press B1 to Start", but LCD only has 16 columns so it would be not fully readable
        setText("Welcome to TOS!\nPress B1 to Play");         
        resetInput();
    }
    if (isButtonPressed(0))
    {
        difficulty = ceil(getPotValue() / 255);
        score=0;
        changeState(STARTING_STATE);
    }
    if (getCurrentTimeInState() > IDLE_TIME)
    {
        changeState(SLEEP_STATE);
    }
    keepControlLedFading();
}

void starting(){
    if (isJustEnteredInState())
    {
        resetOutput();
        setText("GO!");
        score = 0;
    }
    if (getCurrentTimeInState() > DISPLAYING_TIME)
    {
        changeState(GAMING_STATE);
    }
}

void gaming(){
    if (isJustEnteredInState())
    {
        resetInput();
        currentDigit = 0;
        resetLastPressedButton();
        randomSeed(millis());
        for (size_t i = N_LEDS - 1; i > 0; i--) {
            size_t j = random(0, i + 1);
            int t = sequenceNumbers[i];
            sequenceNumbers[i] = sequenceNumbers[j];
            sequenceNumbers[j] = t;
        }

        String str;
        for (size_t i = 0; i < N_LEDS; i++) {
            str += String(sequenceNumbers[i] + 1);
        }
        Serial.println(str);
        setText(str);
    }
    int temp = pressedButton;
    pressedButton = getLastPressedButton();
    if(pressedButton!=temp){
        if(pressedButton>=0 && pressedButton<=3){      
            turnOnLed(pressedButton);      
            checkCorrectSequence(pressedButton);
            
        }
    }
    if (getCurrentTimeInState() > T1 - (FX * score * difficulty))
    {
        changeState(GAME_OVER_STATE);
    }
}

void checkCorrectSequence(int buttoncurrentDigit){
    Serial.print(String("currentDigit ") + currentDigit);
    Serial.print(String("|button ") + buttoncurrentDigit);
    Serial.print(String("|array ") + sequenceNumbers[currentDigit]);
    Serial.println(getCurrentTimeInState());
    if (sequenceNumbers[currentDigit] == buttoncurrentDigit)
    {
        currentDigit++;
        if(currentDigit>=N_LEDS){
            score++;
            delay(1000);
            changeState(END_ROUND_STATE);
        }
    }
    else
    {
        changeState(GAME_OVER_STATE);
    }
}

void endingRound(){
    if (isJustEnteredInState())
    {
        resetOutputLeds();
        String s = "Good! Score: " + String(score);
        setText(s);
    }
    if (getCurrentTimeInState() > DISPLAYING_TIME)
    {
        changeState(GAMING_STATE);
    }
}

void over(){
    if (isJustEnteredInState())
    {
        resetOutput();
        String s="Game Over\nFinal Score:"+String(score);
        setText(s);
        digitalWrite(LS_PIN, HIGH);
    }
    if (getCurrentTimeInState() > LS_DURATION)
    {
        digitalWrite(LS_PIN, LOW);
    }
    if (getCurrentTimeInState() > GAME_OVER_DURATION)
    {
        changeState(INITIAL_STATE);
    }
}