#include "core.h"
#include "config.h"
#include "Arduino.h"
#include "kernel.h"
#include "input.h"
#include "output.h"
#include <Math.h>

extern int difficulty;
extern unsigned int score;
int questionNumberArray[] = {0, 1, 2, 3};
int index = 0;

void initCore()
{
}

void power()
{
    attachInterrupt(digitalPinToInterrupt(B1_PIN), wakeUp, RISING);
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    sleep_mode();
    sleep_disable();
    changeState(INTRO_STATE);
    enableInterrupt(B1_PIN, buttonHandlers[i], CHANGE);
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
    }
    if (isButtonPressed(0))
    {
        difficulty = ceil(getPotValue() / 255);
        changeState(GAMING_STATE);
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
        index = 0;
        const size_t n = sizeof(questionNumberArray) / sizeof(questionNumberArray[0]);
        for (size_t i = 0; i < n - 1; i++)
        {
            size_t j = random(0, n - i);

            int t = questionNumberArray[i];
            questionNumberArray[i] = questionNumberArray[j];
            questionNumberArray[j] = t;
        }
        String str = String(questionNumberArray[0] + 1) + String(questionNumberArray[1] + 1) + String(questionNumberArray[2] + 1) + String(questionNumberArray[3] + 1);
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

    if (getCurrentTimeInState() > T1 - (F * score * difficulty))
    {
        changeState(GAME_OVER_STATE);
    }
}

void checkButtonPressed(int buttonIndex)
{
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
        string s="Game Over\nFinal Score:"+String(score);
        setText(s);
        score = 0;
    }
    if (getCurrentTimeInState() > IDLE_TIME)
    {
        changeState(INTRO_STATE);
    }
}