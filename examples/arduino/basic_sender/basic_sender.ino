/*
 * AREA65 4G Telemetry - Basic Sender
 * 
 * This example sends sensor data to the AREA65 4G module
 * every 2 seconds.
 */

#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
    Serial.begin(115200);      // Debug output
    mySerial.begin(57600);     // Telemetry module

    Serial.println("AREA65 4G Telemetry Sender");
    Serial.println("Initializing...");
}

void loop() {
    // Generate sensor readings
    float P1 = random(5050, 5281) / 100.0;
    float P2 = random(980,  1151) / 100.0;
    float P3 = random(2650, 2721) / 100.0;
    float P4 = random(100,  121)  / 100.0;
    float P5 = random(4800, 5021) / 100.0;
    float P6 = random(550,  681)  / 100.0;

    // Format as JSON
    char buf[120];
    snprintf(buf, sizeof(buf),
        "{\"P1\":%.2f,\"P2\":%.2f,\"P3\":%.2f,"
        "\"P4\":%.2f,\"P5\":%.2f,\"P6\":%.2f}",
        P1, P2, P3, P4, P5, P6);

    // Send to telemetry module
    mySerial.println(buf);
    Serial.println(buf);

    delay(2000);
}
