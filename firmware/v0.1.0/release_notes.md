# AREA65 4G Telemetry Firmware v0.1.0 (Alpha)

**Release Date:** March 2026  
**Status:** Alpha Release  
**License:** MIT

---

## Overview

Initial alpha release of the AREA65 4G Telemetry Module firmware. This release provides basic telemetry data transmission over 4G LTE networks with support for multiple communication interfaces.

---

## Features

### Communication Interfaces
- UART (5V TTL) - 57600 baud (fixed)
- CAN 2.0 - Configurable speed
- SPI (3.3V TTL) - Configurable
- I2C (3.3V TTL) - Configurable

### Data Transmission
- Compact JSON format
- Default 2-second transmission interval
- Parameters P1-P20 supported
- MicroSD backup during network interruption

### Connectivity
- 4G LTE Cat 1 (Quectel EC21)
- GNSS: GPS, GLONASS, BeiDou, Galileo
- LTE-FDD bands: B1, B3, B5, B7, B8, B20

### Cloud Platform
- AREA 65 Live Monitoring integration
- Real-time data visualization
- Configurable dashboard

---

## Installation

### Requirements
- Windows 10/11 (for flasher tool)
- USB-C cable
- AREA65 4G Telemetry Module
- Nano SIM with active data plan

### Flashing Instructions

1. Download `AREA65_FLASHER.exe` from Assets
2. Download `area65_telemetry_v0.1.0.bin` from Assets
3. Connect module via USB-C
4. Run flasher and select .bin file
5. Click Flash and wait for completion
6. Module will reboot automatically

---

## Known Issues (Alpha)

| Issue | Status | Workaround |
|-------|--------|------------|
| UART baud rate fixed at 57600 | By design | Compatible with Spectronik FC |
| No CRC16 checksum | By design | Data integrity via cloud validation |
| Limited to 6 parameters in default config | Known limitation | Use P1-P6 for standard deployment |
| Flasher tool Windows only | In progress | Use USB-UART adapter for manual flash |

---

## Technical Specifications

| Parameter | Value |
|-----------|-------|
| Firmware Version | 0.1.0 |
| Module | Quectel EC21 |
| Power | 5V @ 1A |
| Dimensions | 78 x 57 x 24 mm |
| Weight | 45g |
| Downlink | Max 10 Mbps |
| Uplink | Max 5 Mbps |

---

## File Contents

| File | Description | Size |
|------|-------------|------|
| area65_telemetry_v0.1.0.bin | Firmware binary | TBD |
| AREA65_FLASHER.exe | Windows flasher tool | TBD |
| release_notes.md | This document | - |

---

## Support

- **Documentation:** https://github.com/area65tech/4G-Telemetry/wiki
- **Product Website:** https://area65tech.com/4g-telemetry/
- **Issues:** https://github.com/area65tech/4G-Telemetry/issues
- **Email:** Support via website contact form

---

## Disclaimer

This is alpha software intended for testing and evaluation purposes. Features may change without notice. Not recommended for production deployment.

---

## Changelog

### v0.1.0 (March 2026) - Initial Alpha Release
- First public alpha release
- Basic telemetry data transmission
- Multi-interface support (UART, CAN, SPI, I2C)
- Cloud platform integration
- MicroSD backup functionality
- AREA65_FLASHER.exe tool included
