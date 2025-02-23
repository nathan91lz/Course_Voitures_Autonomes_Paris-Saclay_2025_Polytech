#ifndef DIRECTION_H
#define DIRECTION_H

#include <Arduino.h>
#include <Servo.h>

class Direction {
    private :
        Servo steer;
        uint8_t steerPin;
        const float center = 90.0;
        const float wheelLockMax = 30.0;
        float angle;

    public : 
        Direction(int pin);
        void begin();
        void setAngle(char command);
        float getAngle() const;
        void update();
};

#endif
