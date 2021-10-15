#include <Arduino.h>
#include <Ultrasonic.h>
#include <Servo.h>

int servoPin = 9;
int trigPin = 12;
int echoPin = 13;

Servo servo;
Ultrasonic sensor(trigPin, echoPin);

bool forward = true;

void getSensorData(int pos);

void setup()
{
    Serial.begin(9600);
    pinMode(servoPin, OUTPUT);
    servo.attach(servoPin);

    int currentPos = servo.read();
    for (; currentPos != 0; currentPos--)
    {
        servo.write(currentPos);
        delay(10);
    }
}

void loop()
{
    if (forward)
    {
        for (int pos = 0; pos <= 180; pos++)
        {
            getSensorData(pos);
        }
        forward = false;
        Serial.println("500.500");
    }
    else
    {
        for (int pos = 180; pos >= 0; pos--)
        {
            getSensorData(pos);
        }
        forward = true;
        Serial.println("500.500");
    }
}

void getSensorData(int pos)
{
    servo.write(pos);
    delay(100);
    int distance = sensor.read();

    // 357 is the invalid distance which indicates timeout or out of range.
    while (distance >= 357)
    {
        delay(5);
        distance = sensor.read();
    }
    Serial.print(pos);
    Serial.print(".");
    Serial.println(distance);
}
