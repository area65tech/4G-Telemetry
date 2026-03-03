# Getting Started

This guide will help you set up your AREA65 4G Telemetry Module for the first time.

## Prerequisites

- AREA65 4G Telemetry Module
- Microcontroller (Arduino Uno, ESP32, or Raspberry Pi Pico)
- Active SIM card with data plan
- USB cable for programming
- Jumper wires
- 5V power supply

## Step 1: Insert SIM Card

1. Power off the module
2. Insert SIM card with gold contacts facing down
3. Ensure SIM card clicks into place
4. Attach the 4G antenna

## Step 2: Hardware Connection

Connect the module to your microcontroller:

| AREA65 Pin | Arduino | ESP32 | Raspberry Pi Pico |
|------------|---------|-------|-------------------|
| VCC        | 5V      | 5V    | 5V                |
| GND        | GND     | GND   | GND               |
| TX         | Pin 10  | GPIO16| Pin 9 (RX)        |
| RX         | Pin 11  | GPIO17| Pin 8 (TX)        |

## Step 3: Software Setup

1. Install Arduino IDE or your preferred development environment
2. Select your board type
3. Copy the example code from the examples folder
4. Upload to your microcontroller
5. Open Serial Monitor at 115200 baud

## Step 4: Verification

You should see JSON output every 2 seconds:

```json
{"P1":52.15,"P2":10.45,"P3":26.87,"P4":1.12,"P5":49.33,"P6":6.21}
```

## Next Steps

- [Hardware Integration](Hardware-Integration.md) - Detailed wiring and power requirements
- [API Reference](API-Reference.md) - Data format and protocol details
- [Troubleshooting](Troubleshooting.md) - Common issues and solutions
