# Troubleshooting

Common issues and solutions for the AREA65 4G Telemetry Module.

## Connection Issues

### No Output on Serial Monitor

| Possible Cause | Solution |
|----------------|----------|
| Wrong baud rate | Set Serial Monitor to 115200 |
| Incorrect TX/RX wiring | Swap TX and RX connections |
| Loose connections | Check all wire connections |

### Garbled Output

| Possible Cause | Solution |
|----------------|----------|
| Baud rate mismatch | Verify 57600 for module, 115200 for debug |
| Missing common ground | Connect GND between all devices |
| Electrical interference | Use shielded cables, add capacitor |

## Power Issues

### Module Not Turning On

| Possible Cause | Solution |
|----------------|----------|
| Insufficient current | Use 500mA minimum power supply |
| Reverse polarity | Verify VCC and GND connections |
| Loose power connections | Suggest soldering for permanent installs |

### Intermittent Operation

| Possible Cause | Solution |
|----------------|----------|
| Power supply sag | Add 100uF capacitor near module |
| High current peaks | Use separate power supply for module |

## Network Issues

### No Network Connection

| Possible Cause | Solution |
|----------------|----------|
| SIM card not detected | Re-insert SIM, check orientation |
| No cellular coverage | Check signal strength, relocate antenna |
| SIM PIN enabled | Disable SIM PIN or provide PIN in code |
| Data plan expired | Contact carrier to renew data plan |

### Data Not Transmitting

| Possible Cause | Solution |
|----------------|----------|
| APN not configured | Contact module supplier for APN settings |
| Network registration failed | Power cycle module, check antenna |

## Data Format Issues

### JSON Parse Errors

| Possible Cause | Solution |
|----------------|----------|
| Malformed JSON | Verify snprintf format strings |
| Missing quotes | Ensure proper JSON escaping |
| Truncated data | Increase buffer size |

## Debug Commands

### Serial Monitor Checklist

1. Open Serial Monitor at 115200 baud
2. Verify JSON appears every 2 seconds
3. Check all parameter values are within expected ranges
4. Look for error messages or unusual output

### Hardware Checklist

1. Verify all connections are secure
2. Confirm power supply provides adequate current
3. Check antenna is properly connected
4. Ensure SIM card is inserted correctly

## Contact Support

If issues persist:
1. Document all troubleshooting steps taken
2. Include Serial Monitor output
3. Provide photos of wiring connections
4. Open an issue on GitHub with details
