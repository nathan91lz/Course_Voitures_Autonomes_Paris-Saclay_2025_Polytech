/**
 *  Target : Arduino nano old bootloader
 */
#include <SoftwareSerial.h>
#include "Propulsion.h"
#include "Direction.h"
#include "Data.h"

const long baudRate = 38400; // default BR for RABA DSD TECH 

SoftwareSerial BTSerial(0, 1); // RX, TX
Data data;
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
    if (BTSerial.available()) { // bluetooth command received
        String cmd = BTSerial.readStringUntil('\n'); // get sting data
        Serial.print("Commande reçue : ");
        Serial.println(cmd);
        data.processCommand(cmd);
    }
}
