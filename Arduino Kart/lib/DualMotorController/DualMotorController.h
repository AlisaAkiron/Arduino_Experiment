//
// Created by Liam Sho on 2021/11/26.
//

#ifndef ARDUINO_KART_DUALMOTORCONTROLLER_H
#define ARDUINO_KART_DUALMOTORCONTROLLER_H

#include "L298N.h"
#include "IntersectionType.h"
#include "PID_v1.h"

class DualMotorController {
private:
    bool stopSignal = false;
    uint16_t sampleTime;
    bool testMode;
    L298N *leftMotor;
    L298N *rightMotor;
    u16 turnLeftSpeed;
    u16 turnRightSpeed;
    u16 initLeftSpeed;
    u16 initRightSpeed;
    u16 leftSpeed;
    u16 rightSpeed;
    u16 speedMargin;
    u16 speedMaxMargin;
public:
    explicit DualMotorController(
            uint8_t leftEn, uint8_t leftIn1,
            uint8_t leftIn2, uint8_t rightEn,
            uint8_t rightIn1, uint8_t rightIn2,
            u16 initLeftSpeed, u16 initRightSpeed, uint16_t sampleTime, bool testMode = false);
    void setControlParameters(u16 margin, u16 maxMargin);
    void setTurnSpeed(u16 tls, u16 trs);
    void go(INTERSECTION_TYPE type);
    void stop();
};


#endif //ARDUINO_KART_DUALMOTORCONTROLLER_H
