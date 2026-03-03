# AREA65 4G Telemetry Firmware v0.1.0

## Release Date

March 2026

## Changes

- Initial beta release
- UART communication at 57600 baud
- JSON data output (P1-P6 parameters)
- 2-second transmission interval (default)

## Installation

### Using esptool (ESP32)

```bash
esptool.py --chip esp32 write_flash 0x1000 area65_telemetry_v0.1.0.bin
```

### Using Raspberry Pi Pico

1. Hold BOOTSEL button while connecting USB
2. Copy .bin file to RPI-RP2 drive
3. Device will auto-flash and reboot

## File Information

| File | Description |
|------|-------------|
| area65_telemetry_v0.1.0.bin | Main firmware binary |

## Known Issues

- Beta release - report issues on GitHub

## Support

For issues, visit: https://area65tech.com/4g-telemetry/
