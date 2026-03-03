/*
 * AREA65 4G Telemetry - ESP32 Example
 * 
 * Uses HardwareSerial for better performance.
 */

#include <HardwareSerial.h>

HardwareSerial mySerial(1);

void setup() {
    Serial.begin(115200);
    mySerial.begin(57600, SERIAL_8N1, 16, 17); // RX=GPIO16, TX=GPIO17

    Serial.println("AREA65 4G Telemetry - ESP32");
}

void loop() {
    float P1 = random(5050, 5281) / 100.0;
    float P2 = random(980,  1151) / 100.0;

    String json = "{"P1":" + String(P1, 2) +
                  ","P2":" + String(P2, 2) + "}";

    mySerial.println(json);
    Serial.println(json);
    delay(2000);
}
