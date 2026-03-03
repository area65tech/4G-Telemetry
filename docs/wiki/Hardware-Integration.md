# Hardware Integration

## Interface Options

The AREA65 module supports four communication interfaces that can operate simultaneously:

### UART (TTL, 5V)

| Pin | Function |
|-----|----------|
| TX | Transmit |
| RX | Receive |
| GND | Ground |
| VCC | 5V Power |

**Baud Rate:** 57600 (fixed, Spectronik FC compliant)

### CAN 2.0

| Pin | Function |
|-----|----------|
| CAN_H | CAN High |
| CAN_L | CAN Low |
| GND | Ground |

**Protocol:** CAN 2.0A/B
**Speed:** Configurable

### SPI (TTL, 3.3V)

| Pin | Function |
|-----|----------|
| MOSI | Master Out Slave In |
| MISO | Master In Slave Out |
| SCK | Serial Clock |
| CS | Chip Select |
| GND | Ground |

**Voltage:** 3.3V TTL

### I2C (TTL, 3.3V)

| Pin | Function |
|-----|----------|
| SDA | Serial Data |
| SCL | Serial Clock |
| GND | Ground |

**Voltage:** 3.3V TTL
**Address:** Configurable

## Power Requirements

| Parameter | Value |
|-----------|-------|
| Voltage | 5V DC |
| Current | 1A minimum |
| Connector | USB-C or interface pins |

## Mechanical Dimensions

| Dimension | Value (mm) |
|-----------|------------|
| Length | 78 |
| Width | 57 |
| Height | 24 |
| Weight | 45g |
| Mounting Holes | 2x Ø3.3mm through holes |

## Connector Pinout

Refer to product datasheet for detailed pinout diagrams.
