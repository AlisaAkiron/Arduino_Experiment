//
// Created by Liam Sho on 2021/11/19.
//

#ifndef ARDUINO_KART_INTERSECTIONTYPE_H
#define ARDUINO_KART_INTERSECTIONTYPE_H

enum INTERSECTION_TYPE {
    /**
     * Running straight ahead
     */
    NO_INTERSECTION,
    /**
     * Slightly to left
     */
    SLIGHT_LEFT,
    /**
     * Slightly to right
     */
    SLIGHT_RIGHT,
    /**
     * Far left, it should not happen
     */
    FAR_LEFT,
    /**
     * Far right, it should not happen
     */
    FAR_RIGHT,
    /**
     * Rectangle left intersection
     */
    RECTANGLE_LEFT,
    /**
     * Rectangle right intersection
     */
    RECTANGLE_RIGHT,
    /**
     * Rectangle right or left intersection
     */
    RECTANGLE_LEFT_RIGHT,
    /**
     * Unknown intersection, it should not happen
     */
    UNKNOWN_INTERSECTION
};

#endif //ARDUINO_KART_INTERSECTIONTYPE_H
