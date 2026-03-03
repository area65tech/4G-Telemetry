# AREA65 4G Telemetry Firmware v1.0.0

## Release Date

March 2026

## Changes

- Initial release
- UART communication at 57600 baud
- JSON data output (P1-P6 parameters)
- 2-second transmission interval (default)

## Installation

### Using Arduino IDE

1. Install Arduino IDE
2. Select your board
3. Go to Sketch -> Include Library -> Add .ZIP Library (if using library)
4. Upload the .bin file using your preferred flashing tool

### Using esptool (ESP32)

```bash
esptool.py --chip esp32 write_flash 0x1000 area65_telemetry_v1.0.0.bin
```

### Using Raspberry Pi Pico

1. Hold BOOTSEL button while connecting USB
2. Copy .bin file to RPI-RP2 drive
3. Device will auto-flash and reboot

## File Information

| File | Size | Description |
|------|------|-------------|
| area65_telemetry_v1.0.0.bin | TBD | Main firmware binary |

## Known Issues

- None at this time

## Support

For issues, visit: https://area65tech.com/4g-telemetry/
