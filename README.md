# AREA65 4G Telemetry Module

Plug-and-play LTE Cat 1 telemetry module for M2M and IoT applications with multi-interface support and cloud monitoring.

**Product Website:** https://area65tech.com/4g-telemetry/

---

## Features

- **Multi-Interface Support:** CAN 2.0, UART (TTL 5V), SPI (TTL 3.3V), I2C (TTL 3.3V)
- **Connectivity:** 4G LTE (CAT-1/CAT-4), Wi-Fi capable, GNSS (GPS, GLONASS, BeiDou, Galileo)
- **Storage:** MicroSD card slot (max 32GB) for offline data logging
- **Power:** 5V @ 1A via USB-C or communication interfaces
- **Cloud Platform:** AREA 65 Live Monitoring with customizable GUI, graph plotting, data logging
- **Global Compatibility:** LTE-FDD bands B1, B3, B5, B7, B8, B20

---

## Specifications

| Parameter | Value |
|-----------|-------|
| Module | Quectel EC21 4G Module |
| Dimensions | 78 x 57 x 24 mm |
| Weight | 45g |
| Power | 5V @ 1A |
| 4G Downlink | Max 10 Mbps |
| 4G Uplink | Max 5 Mbps |
| Data Protocol | Compact JSON |
| Interfaces | CAN, UART, I2C, SPI, USB-C |
| GNSS | GPS, GLONASS, BeiDou, Galileo |
| SIM | Nano SIM |
| Storage | MicroSD (max 32GB) |

---

## Quick Start

1. Insert Nano SIM card with active data plan
2. Connect 4G+GPS antenna to SMA connectors
3. Connect microcontroller via CAN, UART, I2C, or SPI
4. Power via USB-C or interface pins (5V @ 1A)
5. Access cloud platform at AREA 65 Live Monitoring
6. Configure GUI, data labels, and visualization

---

## Documentation

- [Getting Started](docs/wiki/Getting-Started.md)
- [Hardware Integration](docs/wiki/Hardware-Integration.md)
- [API Reference](docs/wiki/API-Reference.md)
- [Troubleshooting](docs/wiki/Troubleshooting.md)

---

## Code Examples

| Platform | Interface | Location |
|----------|-----------|----------|
| Arduino | UART | examples/arduino/uart_sender/ |

---

## Firmware

Pre-compiled binaries available in `firmware/` folder and GitHub Releases.

Current Version: v0.1.0

---


## Firmware Updates

Use the AREA65_FLASHER.exe tool located in `firmware/tools/` to update device firmware.

**Download:** [AREA65_FLASHER.exe](firmware/tools/AREA65_FLASHER.exe)

See [Firmware Flasher Guide](firmware/tools/README.md) for detailed instructions.

## License

MIT License - see LICENSE file

---

## Support

For technical support, custom GUI, or local deployable server options, contact via https://area65tech.com/4g-telemetry/
