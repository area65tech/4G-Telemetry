# Arduino Library

## Area65Sender Library

The Area65Sender library provides a professional-grade interface for transmitting multi-parameter data as JSON via SoftwareSerial on Arduino platforms.

### Features

- Dynamic parameter count (1-20 values per transmission)
- Automatic 2-decimal-place formatting of all numerical values
- Built-in rate limiting with configurable delay
- JSON output format: `{"P1":value1,"P2":value2,...,"P20":value20}`
- Error handling for invalid parameter counts
- Non-blocking delay implementation using millis()
- Automatic SoftwareSerial initialization

### Installation

#### Arduino IDE

1. Download the [`area65sender.zip`](../arduino_libraries/area65sender.zip) archive
2. Open Arduino IDE
3. Go to **Sketch** > **Include Library** > **Add .ZIP Library**
4. Select the downloaded `area65sender.zip` file
5. Restart Arduino IDE

#### PlatformIO

Add the following to your `platformio.ini`:

```ini
lib_deps = 
    area65sender
lib_extra_dirs = 
    ../../../../arduino_libraries
```

### Usage

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
  // mySerial is automatically initialized in the Area65Sender constructor
}

void loop() {
  // Send single value (P1 only)
  sender.sendData(1, 12.34);
  
  // Send multiple values (P1, P2, P3)
  sender.sendData(3, 1.5, 2.5, 3.5);
  
  // Send all 20 values
  sender.sendData(20, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0,
                  10.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9);
  
  delay(2000);
}
```

### Methods

#### `sendData(int numValues, ...)`

Transmits 1-20 values as P1-P20 in JSON format.

- `numValues`: Number of values to send (1-20)
- `...`: Variable number of float/double values

All numerical values are automatically converted to 2 decimal places.

Returns `true` on success, `false` if invalid number of values.

#### `setDelay(milliseconds)`

Sets a custom minimum delay between sends. Default is 2000ms.

- `milliseconds`: Minimum delay between sends in milliseconds

If `sendData()` is called before the delay has passed, the send will be skipped.

### Example Projects

- [`Area65 Bidirectional`](../examples/arduino/Area65%20Bidirectional) - Complete bidirectional communication example

### Library Structure

```
arduino_libraries/
├── area65sender/
│   ├── src/
│   │   ├── area65sender.h
│   │   └── area65sender.cpp
│   └── README.md
├── library.properties      # Arduino IDE compatibility
├── library.json           # PlatformIO compatibility
└── area65sender.zip       # Distributable library archive
```

### Technical Specifications

| Parameter | Value |
|-----------|-------|
| Maximum Values | 20 (P1-P20) |
| Default Delay | 2000 ms |
| Baud Rate | 57600 |
| JSON Format | `{"P1":X.XX,"P2":X.XX,...}` |
