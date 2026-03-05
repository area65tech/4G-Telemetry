# Area65Sender Library

A library for sending P1-P20 data values as JSON via SoftwareSerial on Arduino.

## Installation

1. Copy the `area65sender` folder to your Arduino `libraries` folder
2. Restart Arduino IDE

## Usage

```cpp
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <area65sender.h>

// Create SoftwareSerial object (RX, TX)
SoftwareSerial mySerial(10, 11);

// Create Area65Sender instance
Area65Sender sender(mySerial);

void setup() {
  Serial.begin(115200);
  mySerial.begin(57600);
}

void loop() {
  // Send only P1
  sender.sendData(1, 12.34);
  
  // Send P1, P2, P3
  sender.sendData(3, 1.5, 2.5, 3.5);
  
  // Send all 20 values
  sender.sendData(20, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 
                  10.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9);
  
  delay(2000);
}
```

## Methods

### `sendData(int numValues, ...)`
Send 1-20 numerical values as P1-P20 JSON data.

- `numValues`: Number of values to send (1-20)
- `...`: Variable number of float/double values

All numerical values are automatically converted to 2 decimal places.

Returns `true` on success, `false` if invalid number of values.

### `setDelay(milliseconds)`
Set a custom minimum delay between sends. Default is 2000ms.

- `milliseconds`: Minimum delay between sends in milliseconds

If `sendData()` is called before the delay has passed, the send will be skipped.

## Features

- Automatic 2 decimal place conversion for all numerical values
- Built-in delay control to prevent spamming the serial port
- Error handling for invalid number of values (must be 1-20)
- JSON output format: `{"P1":value1,"P2":value2,...}`
