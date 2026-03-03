/*
 * AREA65 4G Telemetry - Arduino UART Example
 * Interface: UART (TTL 5V)
 * Baud Rate: 57600 (fixed)
 */

#include <SoftwareSerial.h>

SoftwareSerial area65(10, 11); // RX, TX

void setup() {
  Serial.begin(115200);      // Debug output
  area65.begin(57600);       // AREA65 module
  delay(1000);
  Serial.println("AREA65 UART Example");
}

void loop() {
  float P1 = analogRead(A0) * (5.0 / 1023.0) * 20.0;  // 0-100V scaled
  float P2 = analogRead(A1) * (5.0 / 1023.0) * 20.0;

  char buf[120];
  snprintf(buf, sizeof(buf),
    "{\"P1\":%.2f,\"P2\":%.2f,\"P3\":0.00,"
    "\"P4\":0.00,\"P5\":0.00,\"P6\":0.00}",
    P1, P2);

  area65.println(buf);
  Serial.println(buf);
  delay(2000);
}
