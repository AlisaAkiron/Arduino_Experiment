//
// Created by Liam Sho on 2021/11/19.
//

#include <Arduino.h>

#include "PathSensor.h"

PathSensor::PathSensor(int pin, int blackCode) {
    this->pin = pin;
    this->blackCode = blackCode;
}

PATH_STATUS PathSensor::getStatus() const {
    return digitalRead(this->pin) == this->blackCode ? PATH_STATUS::BLACK : PATH_STATUS::WHITE;
}
