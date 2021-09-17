#include <Arduino.h>

double functionResult;
double functionVariable;
int amplitude;
int timeCounter;

void setup()
{
    Serial.begin(9600);
    functionVariable = 0.0;
    timeCounter = 0;
    amplitude = random(1, 20);
}

void loop()
{
    timeCounter++;
    if (timeCounter == 650)
    {
        timeCounter = 0;
        amplitude = random(1, 20);
    }
    functionResult = amplitude * sin(functionVariable);
    functionVariable += 0.1;
    Serial.println(functionResult);
}
