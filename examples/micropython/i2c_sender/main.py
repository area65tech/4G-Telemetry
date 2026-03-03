# AREA65 4G Telemetry - MicroPython I2C Example
# Interface: I2C (TTL 3.3V)
# Platform: Raspberry Pi Pico

from machine import I2C, Pin, ADC
import json
import time

i2c = I2C(0, sda=Pin(0), scl=Pin(1), freq=100000)
adc1 = ADC(Pin(26))
adc2 = ADC(Pin(27))

def read_sensor(adc):
    return (adc.read_u16() / 65535.0) * 3.3 * 30.3

while True:
    P1 = round(read_sensor(adc1), 2)
    P2 = round(read_sensor(adc2), 2)

    data = {"P1": P1, "P2": P2}
    json_str = json.dumps(data)

    # Send via I2C (address 0x42 example)
    i2c.writeto(0x42, json_str.encode())

    print(json_str)
    time.sleep(2)
