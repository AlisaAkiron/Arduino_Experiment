#include <Arduino.h>

#include "Configuration.h"

#include "PathSensor.h"
#include "IntersectionDetector.h"
#include "DualMotorController.h"

PathSensor* pathSensor = (PathSensor*)(malloc(sizeof(PathSensor) * PATH_SENSOR_COUNT));
IntersectionDetector intersectionDetector(pathSensor, PATH_SENSOR_COUNT);
DualMotorController dualMotorController(
        LEFT_MOTOR_PIN_EN, LEFT_MOTOR_PIN_1,
        LEFT_MOTOR_PIN_2, RIGHT_MOTOR_PIN_EN,
        RIGHT_MOTOR_PIN_1, RIGHT_MOTOR_PIN_2,
        LEFT_INIT_SPEED, RIGHT_INIT_SPEED,
        SPEED_SAMPLE_TIME, &intersectionDetector, ENABLE_TEST_MODE);

bool status = false;

void setup() {
    Serial.begin(BAUD_RATE);

    pinMode(SWITCH_PIN, OUTPUT);

    pathSensor[0] = PathSensor(PATH_SENSOR_PIN[0], 1);
    pathSensor[1] = PathSensor(PATH_SENSOR_PIN[1], 1);
    pathSensor[2] = PathSensor(PATH_SENSOR_PIN[2], 1);
    pathSensor[3] = PathSensor(PATH_SENSOR_PIN[3], 1);

    dualMotorController.setControlParameters(SPEED_MARGIN, SPEED_MAX_MARGIN);
    dualMotorController.setTurnSpeed(TURN_LEFT_SPEED, TURN_RIGHT_SPEED);
    dualMotorController.setTurnRectParameters(RECT_STRAIGHT_DELAY, RECT_TURN_DELAY);
}

void loop() {

    if(digitalRead(SWITCH_PIN) == HIGH) {
        status = !status;
        delay(1000);
    }

    if (status) {
        dualMotorController.go();
    } else {
        dualMotorController.stop();
    }
}
