/*
 * AREA65 4G Telemetry - ESP32 SPI Example
 * Interface: SPI (TTL 3.3V)
 */

#include <SPI.h>

#define SPI_CS 5
#define SPI_MOSI 23
#define SPI_MISO 19
#define SPI_SCK 18

void setup() {
  Serial.begin(115200);
  SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI, SPI_CS);
  pinMode(SPI_CS, OUTPUT);
  digitalWrite(SPI_CS, HIGH);
  delay(1000);
  Serial.println("AREA65 SPI Example");
}

void loop() {
  float P1 = analogRead(36) * (3.3 / 4095.0) * 30.3;
  float P2 = analogRead(39) * (3.3 / 4095.0) * 30.3;

  String json = "{\"P1\":" + String(P1, 2) +
                ",\"P2\":" + String(P2, 2) + "}";

  digitalWrite(SPI_CS, LOW);
  SPI.transfer((uint8_t*)json.c_str(), json.length());
  digitalWrite(SPI_CS, HIGH);

  Serial.println(json);
  delay(2000);
}
