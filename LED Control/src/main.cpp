#include <Arduino.h>

int ledOutputPin = 11;
int buttonInputPin = 7;
int pinInputVal;
bool ledOn = false;

void setup()
{
    Serial.begin(115200);
    pinMode(ledOutputPin, OUTPUT);
    pinMode(buttonInputPin, INPUT);
}

void loop()
{
    pinInputVal = digitalRead(buttonInputPin);

    if (pinInputVal == HIGH)
    {
        ledOn = !ledOn;
        delay(1000);
    }

    if (ledOn == true)
    {
        digitalWrite(ledOutputPin, HIGH);
    }
    else
    {
        digitalWrite(ledOutputPin, LOW);
    }
}
