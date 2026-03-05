# API Reference

## Data Protocol

### Format

Compact JSON transmitted over selected interface.

### Example Payload

```json
{"P1":52.15,"P2":10.45,"P3":26.87,"P4":1.12,"P5":49.33,"P6":6.21}
```

### Parameters

| Parameter | Description | Range |
|-----------|-------------|-------|
| P1-P20 | Sensor values | 00.00 - 99.99 |

### Transmission Settings

| Setting | Value |
|---------|-------|
| Default Interval | 2000 ms |
| Minimum Interval | 1000 ms |
| Data Integrity | MicroSD backup during network interruption |

## Cloud Platform API

### Features

- User configurable data labels
- Graph plotting and visualization
- Log/save data files
- Print screen capabilities
- Tiered user access (1, 3, or unlimited users)
- Cloud storage (1GB, 3GB, 15GB options)
- 90 days data backup (Premium plans)

### Access

Web browser login to AREA 65 cloud platform.

## Interface Configuration

### UART

| Setting | Value |
|---------|-------|
| Baud Rate | 57600 |
| Data Bits | 8 |
| Parity | None |
| Stop Bits | 1 |
| Voltage | 5V TTL |

### CAN

| Setting | Value |
|---------|-------|
| Protocol | CAN 2.0 |
| Speed | Configurable |
| Voltage | 5V |

### SPI

| Setting | Value |
|---------|-------|
| Mode | 0, 1, 2, 3 |
| Clock | Configurable |
| Voltage | 3.3V TTL |

### I2C

| Setting | Value |
|---------|-------|
| Address | Configurable |
| Speed | Standard/Fast |
| Voltage | 3.3V TTL |

## Arduino Implementation

The Area65Sender library implements this protocol for Arduino platforms:

- Library: [`area65sender`](Arduino-Library.md)
- Default Baud Rate: 57600
- JSON Format: `{"P1":X.XX,"P2":X.XX,...,"P20":X.XX}`
- Maximum Values: 20 parameters per transmission

See the [Arduino Library](Arduino-Library.md) documentation for implementation details and usage examples.
