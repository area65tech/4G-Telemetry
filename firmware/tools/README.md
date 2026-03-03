# AREA65 Firmware Flasher

## Overview

The AREA65_FLASHER.exe is a Windows-based tool for flashing firmware updates to the AREA65 4G Telemetry Module.

## Requirements

- Windows 10/11
- USB-C cable
- AREA65 4G Telemetry Module
- Firmware .bin file

## Usage Instructions

### Step 1: Download Files

1. Download `AREA65_FLASHER.exe` from the tools folder
2. Download the firmware .bin file from Releases

### Step 2: Connect Device

1. Connect the AREA65 module to your PC via USB-C
2. Ensure the module is powered on

### Step 3: Run Flasher

1. Launch `AREA65_FLASHER.exe`
2. Select the firmware .bin file
3. Click "Flash" to begin update
4. Wait for completion (do not disconnect)

### Step 4: Verify

1. Module will reboot automatically
2. Check LED indicators for normal operation
3. Verify firmware version in cloud platform

## Troubleshooting

| Issue | Solution |
|-------|----------|
| Device not detected | Try different USB port/cable |
| Flash failed | Ensure stable power supply |
| Timeout error | Restart module and retry |

## Command Line Usage (Advanced)

```
AREA65_FLASHER.exe --file firmware.bin --port COM3
```

## Support

For issues, contact support via https://area65tech.com/4g-telemetry/
