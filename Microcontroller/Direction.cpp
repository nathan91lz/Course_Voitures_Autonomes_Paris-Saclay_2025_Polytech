#include "Direction.h"

Direction::Direction(int pin) : steerPin(pin), angle(90) {}

void Direction::begin() {
    steer.attach(steerPin);
    Serial.println("Initialisation de la direction ... ");
    steer.write(90);
    delay(500);
}

void Direction::setAngle(char command) {
    if(command == 'd') {
        angle += 1;
        if(angle > (center + wheelLockMax)) angle = (center + wheelLockMax);
    }else if(command == 'q') {
        angle -= 1;
        if(angle < (center - wheelLockMax)) angle = (center - wheelLockMax);
    }
}


float Direction::getAngle() const {
    return angle;
}

void Direction::update() {
    steer.write(angle);

    Serial.print("Angle de braquage : ");
    Serial.println(angle);
}
