#include <Arduino.h>

#include "Configuration.h"

#include "PathSensor.h"
#include "IntersectionDetector.h"

PathSensor* pathSensor = (PathSensor*)(malloc(sizeof(PathSensor) * PATH_SENSOR_COUNT));
IntersectionDetector intersectionDetector(pathSensor, PATH_SENSOR_COUNT);

void setup() {
    Serial.begin(BAUD_RATE);

    pathSensor[0] = PathSensor(PATH_SENSOR_PIN[0], 0);
    pathSensor[1] = PathSensor(PATH_SENSOR_PIN[1], 1);
    pathSensor[2] = PathSensor(PATH_SENSOR_PIN[2], 1);
    pathSensor[3] = PathSensor(PATH_SENSOR_PIN[3], 0);
}

void loop() {
    INTERSECTION_TYPE type = intersectionDetector.getIntersectionType();
    Serial.println(type);
}
