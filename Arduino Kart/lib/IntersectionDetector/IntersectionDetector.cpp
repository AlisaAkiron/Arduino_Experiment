//
// Created by Liam Sho on 2021/11/19.
//

#include <math.h>
#include "IntersectionDetector.h"

IntersectionDetector::IntersectionDetector(PathSensor *pathSensors, int sensorCount) {
    this->pathSensors = pathSensors;
    this->count = sensorCount;
}

INTERSECTION_TYPE IntersectionDetector::getIntersectionType() {
    int statusCode = 0;
    int lev = 1;
    for (int i = 0; i < this->count; i++) {
        statusCode += this->pathSensors[i].getStatus() * lev;
        lev *= 10;
    }

    switch (statusCode) {
        case 110:
            return INTERSECTION_TYPE::NO_INTERSECTION;
        case 10:
            return INTERSECTION_TYPE::SLIGHT_LEFT;
        case 100:
            return INTERSECTION_TYPE::SLIGHT_RIGHT;
        case 1:
            return INTERSECTION_TYPE::FAR_LEFT;
        case 1000:
            return INTERSECTION_TYPE::FAR_RIGHT;
        case 1100:
        case 1110:
            return INTERSECTION_TYPE::RECTANGLE_LEFT;
        case 11:
        case 111:
            return INTERSECTION_TYPE::RECTANGLE_RIGHT;
        case 1111:
            return INTERSECTION_TYPE::RECTANGLE_LEFT_RIGHT;
        default:
            return INTERSECTION_TYPE::UNKNOWN_INTERSECTION;
    }
}
