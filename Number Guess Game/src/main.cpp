#include <Arduino.h>

int input;
int guessNumber;
bool change = false;
bool bingo = false;

void Start_New();

void setup()
{
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);
    Start_New();
}

void loop()
{
    // Bingo 时开始新游戏
    if (bingo == true)
    {
        Start_New();
        bingo = false;
    }

    // 无更改时请求输入
    if (change == false)
    {
        Serial.println("Please input a number (0-9).");
        input = Serial.read();
        delay(1000);
        if (input >= '0' && input <= '9')
        {
            change = true;
        }
    }
    // 有更改时进行判断
    else
    {
        if (input > guessNumber)
        {
            Serial.println("Too Large");
        }
        else if (input < guessNumber)
        {
            Serial.println("Too Small");
        }
        else
        {
            Serial.println("Bingo!");
            bingo = true;
        }
        change = false;
    }
}

void Start_New()
{
    Serial.println("Start a new run.");
    guessNumber = random(1, 10) + '0';
    // Serial.println(guessNumber);
    input = -1;
}
