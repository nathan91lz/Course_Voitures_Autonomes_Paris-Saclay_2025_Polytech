#include "Propulsion.h"

Propulsion::Propulsion(int pin) : motorPin(pin), speed(90) {}

void Propulsion::begin() {
    motor.attach(motorPin);
    Serial.println("Initialisation des moteurs ... ");
    motor.write(90);
    delay(500);
}

void Propulsion::setSpeed(char command) {
    if(command == 'n'){  // neutral
        speed = 90;
    }else if(command == 'z'){ 
        speed += 1;
        if(speed > 180) speed = 180;
    }else if(command == 's'){
        speed -= 1;
        if(speed < 19) speed = 19;
    }else if(command == 'b'){
        speed = 98;
    }else if(command == 'v'){
        speed = 78;
    }
}

float Propulsion::getSpeed() const {
    return (speed - 90) * (maxSpeed / 90.0);
}

void Propulsion::update() {
    motor.write(speed);

    Serial.print("Vitesse PWM : ");
    Serial.print(speed);
    Serial.print(" | Vitesse réelle : ");
    Serial.print(getSpeed());
    Serial.println(" km/h");
}
