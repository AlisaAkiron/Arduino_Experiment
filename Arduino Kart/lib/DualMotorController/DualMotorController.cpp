//
// Created by Liam Sho on 2021/11/26.
//

#include "DualMotorController.h"

#include <Arduino.h>

DualMotorController::DualMotorController(
        uint8_t leftEn, uint8_t leftIn1,
        uint8_t leftIn2, uint8_t rightEn,
        uint8_t rightIn1, uint8_t rightIn2,
        u16 initLeftSpeed, u16 initRightSpeed, uint16_t sampleTime, bool testMode) {
    pinMode(leftEn, OUTPUT);
    pinMode(leftIn1, OUTPUT);
    pinMode(leftIn2, OUTPUT);
    pinMode(rightEn, OUTPUT);
    pinMode(rightIn1, OUTPUT);
    pinMode(rightIn2, OUTPUT);

    this->testMode = testMode;
    this->leftMotor = new L298N(leftEn, leftIn1, leftIn2);
    this->rightMotor = new L298N(rightEn, rightIn1, rightIn2);
    this->initLeftSpeed = initLeftSpeed;
    this->initRightSpeed = initRightSpeed;
    this->leftSpeed = initLeftSpeed;
    this->rightSpeed = initRightSpeed;
    this->sampleTime = sampleTime;
    this->speedMargin = 10;
    this->speedMaxMargin = 50;
    this->turnLeftSpeed = initLeftSpeed - speedMargin;
    this->turnRightSpeed = initRightSpeed - speedMargin;
}

void DualMotorController::setControlParameters(u16 margin, u16 maxMargin) {
    this->speedMargin = margin;
    this->speedMaxMargin = maxMargin;
}

void DualMotorController::go(INTERSECTION_TYPE type) {
    if (stopSignal) {
        this->stop();
        return;
    }

    if (this->testMode) {
        this->leftMotor->setSpeed(this->initLeftSpeed);
        this->rightMotor->setSpeed(this->initRightSpeed);
        this->leftMotor->forward();
        this->rightMotor->forward();
        return;
    }

    switch (type) {
        case NO_INTERSECTION:
            leftSpeed = initLeftSpeed;
            rightSpeed = initRightSpeed;
            break;
        case SLIGHT_LEFT:
            if (leftSpeed < speedMaxMargin + initLeftSpeed) {
                leftSpeed += speedMargin;
                rightSpeed = turnRightSpeed;
            }
            break;
        case SLIGHT_RIGHT:
            if (rightSpeed < speedMaxMargin + initRightSpeed) {
                rightSpeed += speedMargin;
                leftSpeed = turnLeftSpeed;
            }
            break;
        case FAR_LEFT:
            if (leftSpeed < speedMaxMargin + initLeftSpeed) {
                leftSpeed += speedMargin * 2;
                rightSpeed = turnRightSpeed;
            }
            break;
        case FAR_RIGHT:
            if (rightSpeed < speedMaxMargin + initRightSpeed) {
                rightSpeed += speedMargin * 2;
                leftSpeed = turnLeftSpeed;
            }
            break;
        case RECTANGLE_LEFT:
            // TODO: Handler
            break;
        case RECTANGLE_RIGHT:
            // TODO: Handler
            break;
        case RECTANGLE_LEFT_RIGHT:
            this->stopSignal = true;
            this->stop();
            return;
        case UNKNOWN_INTERSECTION:
            break;
    }
    
    this->leftMotor->setSpeed(this->leftSpeed);
    this->rightMotor->setSpeed(this->rightSpeed);
    this->leftMotor->forward();
    this->rightMotor->forward();

    Serial.print(this->leftSpeed);
    Serial.print(" ");
    Serial.print(this->rightSpeed);
    Serial.print(" ");
    Serial.println(type);

    delay(sampleTime);
}

void DualMotorController::stop() {
    this->leftMotor->stop();
    this->rightMotor->stop();
}

void DualMotorController::setTurnSpeed(u16 tls, u16 trs) {
    this->turnLeftSpeed = tls;
    this->turnRightSpeed = trs;
}

