#include <Arduino.h>

int ledRaid[6] = {3, 5, 6, 9, 10, 11};
int brightness[6] = {0, 0, 0, 0, 0, 0};
int maxBrightness = 160;
int startupBrightStep = 30;
int brightStep = 7;
boolean breath[6] = {
    true,
    true,
    true,
    true,
    true,
    true,
};

void setup()
{
    Serial.begin(9600);
    for (int i = 0; i < 6; i++)
    {
        pinMode(ledRaid[i], OUTPUT);
        brightness[i] = startupBrightStep * i;
    }
}

void loop()
{
    for (int i = 0; i < 6; i++)
    {
        if (breath[i])
        {
            brightness[i] += brightStep;
        }
        else
        {
            brightness[i] -= brightStep;
        }

        if (brightness[i] >= maxBrightness)
        {
            breath[i] = false;
            brightness[i] = maxBrightness;
        }
        if (brightness[i] <= 0)
        {
            breath[i] = true;
            brightness[i] = 0;
        }

        analogWrite(ledRaid[i], brightness[i]);
        Serial.println(brightness[i]);
        delay(1);
    }

    Serial.println();
}
