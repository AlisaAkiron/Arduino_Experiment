//
// Created by Liam Sho on 2021/11/19.
//

#ifndef ARDUINO_KART_PATHSTATUS_H
#define ARDUINO_KART_PATHSTATUS_H

enum PATH_STATUS {
    /**
     * Current sensor report a white line. WHITE equals 0.
     */
    WHITE = 0,

    /**
     * Current sensor report a black line. BLACK equals 1.
     */
    BLACK = 1
};

#endif //ARDUINO_KART_PATHSTATUS_H
