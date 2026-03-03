# Hardware Integration

Detailed guide for connecting the AREA65 4G Telemetry Module to various microcontrollers.

## Power Requirements

| Parameter | Value |
|-----------|-------|
| Supply Voltage | 5V DC |
| Peak Current | 500mA |
| Average Current | 200mA |
| Sleep Current | <10mA |

**Note:** Use a power supply capable of delivering at least 500mA to ensure reliable operation during network transmission peaks.

## Pin Configuration

### AREA65 Module Pinout

| Pin | Name | Description |
|-----|------|-------------|
| 1 | VCC | Power supply (5V) |
| 2 | GND | Ground |
| 3 | TX | UART transmit |
| 4 | RX | UART receive |
| 5 | NET | Network status LED |
| 6 | RST | Reset (active low) |

## Microcontroller Connections

### Arduino Uno/Nano

| AREA65 | Arduino |
|--------|---------|
| VCC | 5V |
| GND | GND |
| TX | Pin 10 |
| RX | Pin 11 |

### ESP32

| AREA65 | ESP32 |
|--------|-------|
| VCC | 5V |
| GND | GND |
| TX | GPIO16 |
| RX | GPIO17 |

### Raspberry Pi Pico

| AREA65 | Pico |
|--------|------|
| VCC | 5V |
| GND | GND |
| TX | Pin 9 (RX) |
| RX | Pin 8 (TX) |

## Wiring Best Practices

1. Keep UART wires as short as possible (<30cm)
2. Use twisted pair for TX/RX lines
3. Add 10uF capacitor between VCC and GND near module
4. Ensure common ground between all devices
5. Use level shifter if connecting to 3.3V logic devices

## Antenna Connection

- Use the included 4G antenna
- Screw on firmly but do not overtighten
- Position antenna vertically for best reception
- Keep antenna away from metal objects
