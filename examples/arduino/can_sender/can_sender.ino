/*
 * AREA65 4G Telemetry - Arduino CAN Example
 * Interface: CAN 2.0
 * Library: MCP2515 CAN Module
 */

#include <SPI.h>
#include <mcp_can.h>

#define CAN_CS_PIN 10
MCP_CAN CAN(CAN_CS_PIN);

void setup() {
  Serial.begin(115200);

  if (CAN.begin(MCP_500KBPS) == CAN_OK) {
    Serial.println("CAN Init OK");
  } else {
    Serial.println("CAN Init Failed");
  }
  delay(1000);
}

void loop() {
  float P1 = analogRead(A0) * (5.0 / 1023.0) * 20.0;
  float P2 = analogRead(A1) * (5.0 / 1023.0) * 20.0;

  char jsonBuf[120];
  snprintf(jsonBuf, sizeof(jsonBuf),
    "{\"P1\":%.2f,\"P2\":%.2f}", P1, P2);

  // Send via CAN (8 bytes max per frame)
  CAN.sendMsgBuf(0x100, 0, 8, (uint8_t*)jsonBuf);

  Serial.println(jsonBuf);
  delay(2000);
}
