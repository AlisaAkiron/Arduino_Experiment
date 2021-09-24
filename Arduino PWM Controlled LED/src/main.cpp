#include <Arduino.h>

int AnalogInputPort = 0;
int OutputLED = 11;

void setup()
{
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(50);
    digitalWrite(LED_BUILTIN, LOW);
    delay(50);

    // Anaload Voltage value is between 0 to 1024
    double analogVoltage = analogRead(AnalogInputPort);
    Serial.println(analogVoltage);

    // Divide 4 to make this value between 0 to 255
    // The max output value of PWM is 255
    analogWrite(OutputLED, analogVoltage / 4);
    delay(10);
}
