#ifndef PROPULSION_H
#define PROPULSION_H

#include <Arduino.h>
#include <Servo.h>

class Propulsion {
  private:
    Servo motor;
    uint8_t motorPin;
    const float maxSpeed = 50.0;
    float speed;

  public:
    Propulsion(int pin); 
    void begin();
    void setSpeed(char command);
    float getSpeed() const;
    void update();
};

#endif
