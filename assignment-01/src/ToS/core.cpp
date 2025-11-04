/*  Foschini Paolo    0001122840
*   Pertegato Marco   0001123050
*   Sargov Valerii    0001124110
*/
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

void initCore()
{
    Serial.begin(9600);
    pressedButton = -1;
    difficulty = 0;
    score = 0;
    currentDigit = 0;
}

void sleeping()
{
    Serial.println("GOING IN POWER DOWN ...");
    Serial.flush();
    delay(100);
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

void initializing()
{
    if (isJustEnteredInState())
    {
        setText("Welcome to TOS!\nPress B1 to Play");   // Should be:"Press B1 to Start", but LCD only has 16 columns so it would be not fully readable
        resetInput();
    }
    if (isButtonPressed(0))
    {
        difficulty = ceil(getPotValue() / 255);
        score = 0;
        changeState(STARTING_STATE);
    }
    if (getCurrentTimeInState() > IDLE_TIME)
    {
        changeState(SLEEP_STATE);
    }
    keepControlLedFading();
}

void starting()
{
    if (isJustEnteredInState())
    {
        resetOutput();
        String s = "GO!\nDifficulty: " + String(difficulty);    // Sligthly modified the message to show the Difficuly at the start of the game
        setText(s);
    }
    if (getCurrentTimeInState() > DISPLAYING_TIME)
    {
        changeState(GAMING_STATE);
    }
}

void gaming()
{
    if (isJustEnteredInState())
    {
        resetInput();
        currentDigit = 0;
        resetLastPressedButton();
        randomSeed(millis());
        for (size_t i = N_LEDS - 1; i > 0; i--)
        {
            size_t j = random(0, i + 1);
            int t = sequenceNumbers[i];
            sequenceNumbers[i] = sequenceNumbers[j];
            sequenceNumbers[j] = t;
        }

        String str;
        for (size_t i = 0; i < N_LEDS; i++)
        {
            str += String(sequenceNumbers[i] + 1);
        }
        setText(str);
    }
    int temp = pressedButton;
    pressedButton = getLastPressedButton();
    if (pressedButton != temp)      // User can insert two time consecutively the same number, cause the array cannot contain duplicates
    {
        if (pressedButton >= 0 && pressedButton <= 3)
        {
            turnOnLed(pressedButton);
            checkCorrectSequence(pressedButton);
        }
    }
    if (getCurrentTimeInState() > T1 - (FX * score * difficulty))
    {
        changeState(GAME_OVER_STATE);
    }
}

void checkCorrectSequence(int buttoncurrentDigit)
{
    if (sequenceNumbers[currentDigit] == buttoncurrentDigit)
    {
        currentDigit++;
        if (currentDigit >= N_LEDS)
        {
            score++;
            delay(2000);    //Delay needed to show for 1sec all green leds ON before transitioning to the End Round State
            changeState(END_ROUND_STATE);
        }
    }
    else
    {
        changeState(GAME_OVER_STATE);
    }
}

void endingRound()
{
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

void over()
{
    if (isJustEnteredInState())
    {
        resetOutput();
        String s = "Game Over\nFinal Score:" + String(score);
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