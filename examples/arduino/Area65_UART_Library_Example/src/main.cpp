// Include the Area65UART library
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <area65_uart.h>

// Create SoftwareSerial object (RX, TX)
SoftwareSerial mySerial(10, 11);

// Create Area65UART instance
Area65UART sender(mySerial);

void setup() {
  Serial.begin(115200);
  // mySerial is automatically initialized in the Area65UART constructor
}

void loop() {
  // Send only P1 with value 12.34
  sender.sendData(1, 12.34);
  
  // Send P1, P2, P3 with custom values
  sender.sendData(3, 1.5, 2.5, 3.5);
  
  // Send all 20 values with custom data
  sender.sendData(20, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 
                  10.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9);
  
  // Error case - more than 20 values (will print error message)
  // sender.sendData(21, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 
  //                 10.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 11.0);
  
  delay(2000);
}