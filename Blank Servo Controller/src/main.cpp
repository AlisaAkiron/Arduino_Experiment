#include <Arduino.h>

int servoPin = 9;
int angle;

void servoPulseController(int angle);

void setup()
{
    Serial.begin(9600);
    pinMode(servoPin, OUTPUT);
    Serial.println("Init complete.");
}

void loop()
{
    int value = Serial.read();
    if (value >= '0' && value <= '9')
    {
        value = value - '0';
        angle = value * 20;
        Serial.println("Current angle = ");
        Serial.println(angle, DEC);
    }

    for (int i = 0; i <= 50; i++)
    {
        servoPulseController(angle);
    }
}

void servoPulseController(int angle)
{
    int pulseWidth = (angle * 11) + 500;
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(pulseWidth);
    digitalWrite(servoPin, LOW);
    delay(20 - pulseWidth / 1000);
}
