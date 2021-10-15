#include <Arduino.h>
#include <Ultrasonic.h>

int trigPin = 12;
int echoPin = 13;

Ultrasonic sensor(trigPin, echoPin);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.print("Distance: ");
    int value = sensor.read();
    if (value >= 357)
    {
        Serial.println("OUT_OF_RANGE_EXCEPTION");
    }
    else
    {
        Serial.print(value);
        Serial.println(" cm");
    }

    delay(500);
}
