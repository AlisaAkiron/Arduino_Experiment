//
// Created by Liam Sho on 2021/11/19.
//

#ifndef ARDUINO_KART_INTERSECTIONDETECTOR_H
#define ARDUINO_KART_INTERSECTIONDETECTOR_H

#include "PathSensor.h"
#include "IntersectionType.h"

class IntersectionDetector {
private:
    PathSensor* pathSensors;
    int count;
public:
    explicit IntersectionDetector(PathSensor* sensors, int sensorCount);
    INTERSECTION_TYPE getIntersectionType();
};

#endif //ARDUINO_KART_INTERSECTIONDETECTOR_H
