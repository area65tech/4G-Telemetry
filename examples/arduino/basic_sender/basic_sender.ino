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
char p1[10];
char p2[10];
char p3[10];
char p4[10];
char p5[10];
char p6[10];

dtostrf(P1, 0, 2, p1);
dtostrf(P2, 0, 2, p2);
dtostrf(P3, 0, 2, p3);
dtostrf(P4, 0, 2, p4);
dtostrf(P5, 0, 2, p5);
dtostrf(P6, 0, 2, p6);

char buf[200];

sprintf(buf,
    "{\"P1\":%s,\"P2\":%s,\"P3\":%s,"
    "\"P4\":%s,\"P5\":%s,\"P6\":%s}",
    p1, p2, p3, p4, p5, p6);

Serial.println(buf);

    // Send to telemetry module
    mySerial.println(buf);
    Serial.println(buf);

    delay(2000);
}