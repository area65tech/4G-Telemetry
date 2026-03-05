#include "Arduino.h"
#include "area65sender.h"
#include <stdarg.h>

Area65Sender::Area65Sender(SoftwareSerial& serial) {
  _serial = &serial;
  _lastSendTime = 0;
  _minDelay = MIN_SEND_DELAY;
  _serial->begin(DEFAULT_SERIAL_BAUD);
}

void Area65Sender::setDelay(int milliseconds) {
  _minDelay = (milliseconds > 0) ? milliseconds : 0;
}

bool Area65Sender::sendData(float firstValue, ...) {
  va_list args;
  va_start(args, firstValue);
  
  _values[0] = firstValue;
  int count = 1;
  
  while (count < MAX_VALUES) {
    float nextVal = va_arg(args, float);
    _values[count] = nextVal;
    count++;
  }
  
  va_end(args);
  
  return true;
}

bool Area65Sender::sendData(int numValues, ...) {
  if (numValues < 1 || numValues > MAX_VALUES) {
    Serial.println(F("ERROR: Invalid number of values. Must be 1 to 20."));
    return false;
  }
  
  va_list args;
  va_start(args, numValues);
  
  for (int i = 0; i < numValues; i++) {
    _values[i] = va_arg(args, double);
  }
  
  va_end(args);
  
  unsigned long currentTime = millis();
  if (currentTime - _lastSendTime < _minDelay) {
    return true;
  }
  
  sendJson(numValues);
  
  _lastSendTime = currentTime;
  
  return true;
}

void Area65Sender::sendJson(int numValues) {
  char buffers[MAX_VALUES][8];
  
  for (int i = 0; i < numValues; i++) {
    dtostrf(_values[i], 5, 2, buffers[i]);
  }
  
  char buf[500];
  int written = snprintf(buf, sizeof(buf), "{");
  
  for (int i = 0; i < numValues; i++) {
    if (i > 0) {
      written += snprintf(buf + written, sizeof(buf) - written, ",");
    }
    written += snprintf(buf + written, sizeof(buf) - written, "\"P%d\":%s", i + 1, buffers[i]);
  }
  
  written += snprintf(buf + written, sizeof(buf) - written, "}");
  
  _serial->println(buf);
  
  Serial.println(buf);
}
