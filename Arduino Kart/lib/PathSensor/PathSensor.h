//
// Created by Liam Sho on 2021/11/19.
//

#ifndef ARDUINO_KART_PATHSENSOR_H
#define ARDUINO_KART_PATHSENSOR_H

#include "PathStatus.h"

class PathSensor {
private:
    int pin;
    int blackCode;
public:
    PathSensor(int pin, int blackCode);
    PATH_STATUS getStatus() const;
};

#endif //ARDUINO_KART_PATHSENSOR_H
