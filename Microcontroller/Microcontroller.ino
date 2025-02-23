/**
 *  Target : Arduino nano old bootloader
 */
#include <SoftwareSerial.h>
#include "Propulsion.h"


const long baudRate = 38400; // default BR for RABA DSD TECH 

SoftwareSerial BTSerial(0, 1); // RX, TX
Propulsion motor(9); //pin 9

void setup() {
  Serial.begin(9600); // USB
  BTSerial.begin(baudRate); // Bt

  BTSerial.println("Hello from Arduino");
  Serial.println("Hello from Arduino");

  motor.begin();
}

void loop() {
    if (Serial.available()) { // Bluetooth command received
        char commande = Serial.read();
        Serial.print("Commande reçue : ");
        Serial.println(commande);
        
        motor.setSpeed(commande); 
        motor.updateMotor(); 
    }
}
