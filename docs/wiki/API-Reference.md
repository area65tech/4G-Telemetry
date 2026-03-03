# API Reference

Technical specification for the AREA65 4G Telemetry data protocol.

## Communication Protocol

### UART Settings

| Parameter | Value |
|-----------|-------|
| Baud Rate | 57600 |
| Data Bits | 8 |
| Parity | None |
| Stop Bits | 1 |
| Flow Control | None |

### Data Format

All data is transmitted as JSON strings, terminated with a newline character.

```json
{"P1":52.15,"P2":10.45,"P3":26.87,"P4":1.12,"P5":49.33,"P6":6.21}
```

## Parameter Specification

### Sensor Values (P1-P6)

| Parameter | Type | Range | Precision |
|-----------|------|-------|-----------|
| P1 | Float | 0.00-99.99 | 2 decimal places |
| P2 | Float | 0.00-99.99 | 2 decimal places |
| P3 | Float | 0.00-99.99 | 2 decimal places |
| P4 | Float | 0.00-99.99 | 2 decimal places |
| P5 | Float | 0.00-99.99 | 2 decimal places |
| P6 | Float | 0.00-99.99 | 2 decimal places |

### Extended Parameters (P7-P20)

Additional parameters follow the same format and can be used for custom sensor data.

## Timing

| Operation | Interval |
|-----------|----------|
| Default Transmission | 2000ms |
| Minimum Interval | 1000ms |
| Maximum Interval | No limit |

## Example Payloads

### Standard 6-Parameter

```json
{"P1":25.50,"P2":60.25,"P3":30.00,"P4":1.05,"P5":48.75,"P6":5.80}
```

### Minimal 2-Parameter

```json
{"P1":25.50,"P2":60.25}
```

### Extended 10-Parameter

```json
{"P1":25.50,"P2":60.25,"P3":30.00,"P4":1.05,"P5":48.75,"P6":5.80,"P7":12.34,"P8":56.78,"P9":90.12,"P10":34.56}
```

## Notes

- Baud rate is fixed at 57600 (Spectronik FC compliant)
- No CRC checksum (intentional by design)
- Parameters P1-P20 are fixed in code for universal compatibility
- JSON must be valid and properly formatted
