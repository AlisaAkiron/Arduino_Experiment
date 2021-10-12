#include <Arduino.h>
#include <L298N.h>

enum motorModes
{
    FORWARD,
    BACKWARD,
    TURN_RIGHT,
    TURN_LEFT,
    STOP
};

int motorInput1 = 5;
int motorInput2 = 6;

int motorInput3 = 9;
int motorInput4 = 10;

int motorSpeed = 200;

motorModes motorMode = motorModes::STOP;

L298N motorLeft(motorInput1, motorInput2);
L298N motorRight(motorInput3, motorInput4);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int input = Serial.read();
    switch (input)
    {
    case '2':
        if (motorSpeed + 10 <= 240)
        {
            motorSpeed += 10;
            motorLeft.setSpeed(motorSpeed);
            motorRight.setSpeed(motorSpeed);
            Serial.println("Change speed to =>");
            Serial.println(motorSpeed, DEC);
        }
        break;
    case '1':
        if (motorSpeed - 10 >= 0)
        {
            motorSpeed -= 10;
            motorLeft.setSpeed(motorSpeed);
            motorRight.setSpeed(motorSpeed);
            Serial.println("Change speed to =>");
            Serial.println(motorSpeed, DEC);
        }
        break;
    case 'w':
        motorMode = motorModes::FORWARD;
        Serial.println("Change motor mode to motorModes::FORWARD");
        break;
    case 's':
        motorMode = motorModes::BACKWARD;
        Serial.println("Change motor mode to motorModes::BACKWARD");
        break;
    case 'a':
        motorMode = motorModes::TURN_LEFT;
        Serial.println("Change motor mode to motorModes::TURN_LEFT");
        break;
    case 'd':
        motorMode = motorModes::TURN_RIGHT;
        Serial.println("Change motor mode to motorModes::TURN_RIGHT");
        break;
    case 'x':
        motorMode = motorModes::STOP;
        Serial.println("Change motor mode to motorModes::STOP");
    default:
        break;
    }

    switch (motorMode)
    {
    case motorModes::FORWARD:
        motorLeft.forward();
        motorRight.forward();
        break;
    case motorModes::BACKWARD:
        motorLeft.backward();
        motorRight.backward();
        break;
    case motorModes::STOP:
        motorLeft.stop();
        motorRight.stop();
        break;
    case motorModes::TURN_LEFT:
        motorLeft.backward();
        motorRight.forward();

        break;
    case motorModes::TURN_RIGHT:
        motorLeft.forward();
        motorRight.backward();
        break;
    default:
        break;
    }
}
