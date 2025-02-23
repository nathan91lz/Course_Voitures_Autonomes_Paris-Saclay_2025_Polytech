#include "Propulsion.h"

Propulsion::Propulsion(int pin) : motorPin(pin), speed(90) {}

void Propulsion::begin(){
    motor.attach(motorPin);
    Serial.println("Initialisation des moteurs ... ");
    motor.write(90);
    delay(1000);
}

void Propulsion::setSpeed(char command){
    if(command == 's'){
        speed = 90;
    }else if(command == 'a'){
        speed += 1;
        if(speed > 180) speed = 180;
    }else if(command == 'd'){
        speed -= 1;
        if(speed < 0) speed = 0;
    }
}

float Propulsion::getSpeed() const{
    return (speed - 90) * (maxSpeed / 90.0);
}

void Propulsion::updateMotor(){
    motor.write(speed);

    Serial.print("Vitesse PWM : ");
    Serial.print(speed);
    Serial.print(" | Vitesse réelle : ");
    Serial.print(getSpeed());
    Serial.println(" km/h");
}
