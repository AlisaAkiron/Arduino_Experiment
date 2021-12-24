//
// Created by Liam Sho on 2021/11/19.
//

#ifndef ARDUINO_KART_CONFIGURATION_H
#define ARDUINO_KART_CONFIGURATION_H

/************************/
/*    Pin Definition    */
/************************/

int const PATH_SENSOR_PIN[] = { 8, 7, 4, 2 };
int const PATH_SENSOR_COUNT = 4;

#define LEFT_MOTOR_PIN_EN 3
#define LEFT_MOTOR_PIN_1 6
#define LEFT_MOTOR_PIN_2 5
#define RIGHT_MOTOR_PIN_EN 11
#define RIGHT_MOTOR_PIN_1 10
#define RIGHT_MOTOR_PIN_2 9

#define SWITCH_PIN 13

// =================================================== //

/************************/
/*        Other         */
/************************/

#define BAUD_RATE 9600

#define LEFT_INIT_SPEED 110
#define RIGHT_INIT_SPEED 110
#define TURN_LEFT_SPEED 90
#define TURN_RIGHT_SPEED 90
#define SPEED_MARGIN 20
#define SPEED_MAX_MARGIN 100

#define RECT_STRAIGHT_DELAY 400
#define RECT_TURN_DELAY 800

#define SPEED_SAMPLE_TIME 10
#define ENABLE_TEST_MODE false

#endif //ARDUINO_KART_CONFIGURATION_H
