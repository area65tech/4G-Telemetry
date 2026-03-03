# AREA65 4G Telemetry Module

Wireless data transmission from microcontrollers to remote systems via cellular networks.

**Product Website:** https://area65tech.com/4g-telemetry/

## Overview

The AREA65 4G Telemetry Module enables IoT devices to send sensor data over 4G LTE networks without requiring WiFi or Ethernet connectivity. Designed for remote monitoring applications where cellular coverage is available but traditional internet infrastructure is not.

## Features

- 4G LTE connectivity (LTE Cat-1)
- UART interface (57600 baud)
- JSON data format
- Plug-and-play integration with Arduino, ESP32, STM32, Raspberry Pi Pico
- Low power consumption
- Global cellular network support

## Quick Start

### Hardware Connections

| Microcontroller | AREA65 Module |
|-----------------|---------------|
| Pin 10 (TX)     | RX            |
| Pin 11 (RX)     | TX            |
| GND             | GND           |
| 5V              | VCC           |

### Basic Example (Arduino)

```cpp
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);

void setup() {
    Serial.begin(115200);
    mySerial.begin(57600);
}

void loop() {
    String json = "{"P1":25.50,"P2":60.25}";
    mySerial.println(json);
    Serial.println(json);
    delay(2000);
}
```

## Documentation

- [Getting Started](docs/wiki/Getting-Started.md)
- [Hardware Integration](docs/wiki/Hardware-Integration.md)
- [API Reference](docs/wiki/API-Reference.md)
- [Troubleshooting](docs/wiki/Troubleshooting.md)

## Firmware

Pre-compiled firmware binaries are available in the `firmware/` folder and as [GitHub Releases](https://github.com/area65tech/4G-Telemetry/releases).

### Firmware Folder Structure

```
firmware/
├── v0.1.0/
│   ├── area65_telemetry_v0.1.0.bin
│   └── release_notes.md
└── latest.bin -> v0.1.0/area65_telemetry_v0.1.0.bin
```

### Using GitHub Releases

Firmware binaries are distributed via GitHub Releases:

1. Go to [Releases page](https://github.com/area65tech/4G-Telemetry/releases)
2. Download the latest `.bin` file
3. Flash to your device using your preferred tool

**Note:** Firmware source code is proprietary. Only compiled binaries are distributed.

## Repository Structure

```
area65-4g-telemetry/
├── README.md
├── LICENSE
├── .gitignore
├── firmware/
│   └── v0.1.0/
│       ├── area65_telemetry_v0.1.0.bin
│       └── release_notes.md
├── docs/
│   └── wiki/
│       ├── Getting-Started.md
│       ├── Hardware-Integration.md
│       ├── API-Reference.md
│       └── Troubleshooting.md
├── examples/
│   ├── arduino/
│   ├── esp32/
│   └── micropython/
└── hardware/
    ├── schematics/
    └── datasheets/
```

## Requirements

- AREA65 4G Telemetry Module
- Active SIM card with data plan
- Microcontroller (Arduino, ESP32, etc.)
- 5V power supply (500mA minimum)
- 4G antenna (included with module)

## Technical Specifications

| Parameter             | Value                    |
|-----------------------|--------------------------|
| Interface             | UART (TTL)               |
| Baud Rate             | 57600 (fixed)            |
| Data Format           | JSON                     |
| Supply Voltage        | 5V                       |
| Current Consumption   | 500mA (peak)             |
| Operating Temperature | -20C to +70C             |
| Network               | 4G LTE Cat-1             |

## Support

For issues and questions:
- Visit: https://area65tech.com/4g-telemetry/
- Open an issue on GitHub
- Refer to the [Troubleshooting Guide](docs/wiki/Troubleshooting.md)

## License

MIT License - see [LICENSE](LICENSE) for details.

Firmware is proprietary software. Binary distribution only.
