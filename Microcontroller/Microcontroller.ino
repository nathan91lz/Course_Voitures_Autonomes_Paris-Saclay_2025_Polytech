#include <SoftwareSerial.h>

const long baudRate = 38400; // default BR for RABA DSD TECH 

SoftwareSerial BTSerial(0, 1); // RX, TX

void setup() {
  Serial.begin(9600); // USB
  BTSerial.begin(baudRate); // Bt
}

void loop() {
    BTSerial.println("Hello from Arduino");
    Serial.println("Hello from Arduino");
    delay(1000);
}
