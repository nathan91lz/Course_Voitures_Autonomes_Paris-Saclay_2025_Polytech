/**
 *  Target : Arduino nano old bootloader
 */
#include <SoftwareSerial.h>
#include "Propulsion.h"
#include "Direction.h"

const long baudRate = 38400; // default BR for RABA DSD TECH 

SoftwareSerial BTSerial(0, 1); // RX, TX
Propulsion motor(9); //pin 9
Direction steer(10); //pin 10

void setup() {
  Serial.begin(9600); // USB
  BTSerial.begin(baudRate); // Bt

  BTSerial.println("Hello from Arduino");
  Serial.println("Hello from Arduino");

  motor.begin();
  steer.begin();
}

void loop() {
    if (BTSerial.available()) { // Bluetooth command received
        char commande = BTSerial.read();
        Serial.print("Commande reçue : ");
        Serial.println(commande);
        BTSerial.print("Commande reçue : ");
        BTSerial.println(commande);
        
        motor.setSpeed(commande); 
        motor.update(); 

        steer.setAngle(commande);
        steer.update();
    }
}
