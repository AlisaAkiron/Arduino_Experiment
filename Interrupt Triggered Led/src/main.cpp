#include <Arduino.h>
#include <MsTimer2.h>

void Interrupt_RandomSpeed();
void Interrupt_ChangeLedStatus();

volatile bool ledStatus = false;
volatile int interval = 100;

void setup()
{
    Serial.begin(9600);

    // Setup pin mode
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(2, INPUT);

    // Setup outter interrupt
    attachInterrupt(INT0, Interrupt_RandomSpeed, FALLING);

    // Setup inner interrupt
    MsTimer2::set(interval, Interrupt_ChangeLedStatus);
    MsTimer2::start();
}

void loop()
{
    if (ledStatus == true)
    {
        digitalWrite(LED_BUILTIN, HIGH);
    }
    else
    {
        digitalWrite(LED_BUILTIN, LOW);
    }
}

void Interrupt_RandomSpeed()
{
    // Stop MsTimer Interrupt
    MsTimer2::stop();

    // Generate a random interval value (100 - 4000 ms)
    interval = random(100, 4001);
    Serial.println(interval);

    // Reset and start the MsTimer Interrupt
    MsTimer2::set(interval, Interrupt_ChangeLedStatus);
    MsTimer2::start();
}

void Interrupt_ChangeLedStatus()
{
    // Change the status of led
    ledStatus = !ledStatus;
}
