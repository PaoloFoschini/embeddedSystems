#include "core.h"
#include "config.h"
#include "Arduino.h"
#include "kernel.h"
#include "input.h"
#include "output.h"
#include <Math.h>
#include <avr/sleep.h>

extern int difficulty;
extern unsigned int score;
int questionNumberArray[] = {0, 1, 2, 3};
int index = 0;

void initCore()
{
}

void wakeUp(){}

void power()
{
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    sleep_mode();
    sleep_disable();
    changeState(INTRO_STATE);
}

void starting()
{
    if (isJustEnteredInState())
    {
        resetOutput();
        setText("GO!");
        score = 0;
    }
    if (getCurrentTimeInState() > GO_TIME)
    {
        changeState(GAMING_STATE);
    }
}

void continuing()
{
    if (isJustEnteredInState())
    {
        resetOutputLeds();
        String s = "Good! Score: " + String(score);
        setText(s);
    }
    if (getCurrentTimeInState() > CONTINUE_TIME)
    {
        changeState(GAMING_STATE);
    }
}

void intro()
{
    if (isJustEnteredInState())
    {
        setText("Welcome to TOS!\nPress B1 to Start");
        resetInput();
    }
    if (isButtonPressed(0))
    {
        difficulty = ceil(getPotValue() / 255);
        Serial.println(difficulty);
        changeState(STARTING_STATE);
    }
    if (getCurrentTimeInState() > IDLE_TIME)
    {
        changeState(POWER_STATE);
    }
    keepControlLedFading();
}

void gaming()
{
    if (isJustEnteredInState())
    {
        resetInput();
        index = 0;/*
        const size_t n = sizeof(questionNumberArray) / sizeof(questionNumberArray[0]);
        for (size_t i = 0; i < n - 1; i++)
        {
            size_t j = random(0, n - i);

            int t = questionNumberArray[i];
            questionNumberArray[i] = questionNumberArray[j];
            questionNumberArray[j] = t;
        }*/
        String str = String(questionNumberArray[0] + 1) + String(questionNumberArray[1] + 1) + String(questionNumberArray[2] + 1) + String(questionNumberArray[3] + 1);
        Serial.println(str);
        setText(str);
    }
    
    if (isButtonPressed(0))
    {
        checkButtonPressed(0);
    }
    if (isButtonPressed(1))
    {
        checkButtonPressed(1);
    }
    if (isButtonPressed(2))
    {
        checkButtonPressed(2);
    }
    if (isButtonPressed(3))
    {
        checkButtonPressed(3);
    }

    if (getCurrentTimeInState() > T1 - (FX * score * difficulty))
    {
        changeState(GAME_OVER_STATE);
    }
}

void checkButtonPressed(int buttonIndex)
{
    Serial.println(String("index ") + index);
    Serial.println(String("button ") + buttonIndex);
    Serial.println(String("array ") + questionNumberArray[index]);
    if (questionNumberArray[index] == buttonIndex)
    {
        index++;
    }
    else
    {
        changeState(GAME_OVER_STATE);
    }
}

void over()
{
    if (isJustEnteredInState())
    {
        resetOutput();
        String s="Game Over\nFinal Score:"+String(score);
        setText(s);
        score = 0;
        analogWrite(LS_PIN, 255);
    }
    if (getCurrentTimeInState() > 2000)
    {
        analogWrite(LS_PIN, 0);
    }
    if (getCurrentTimeInState() > IDLE_TIME)
    {
        changeState(INTRO_STATE);
    }
}