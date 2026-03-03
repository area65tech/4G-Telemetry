"""
AREA65 4G Telemetry - MicroPython Example
For Raspberry Pi Pico
"""

from machine import UART, Pin
import random
import json
import time

uart = UART(1, baudrate=57600, tx=Pin(8), rx=Pin(9))

print("AREA65 4G Telemetry - MicroPython")

while True:
    data = {
        "P1": round(random.uniform(50.50, 52.81), 2),
        "P2": round(random.uniform(9.80, 11.51), 2)
    }

    json_str = json.dumps(data)
    uart.write(json_str + "\n")
    print(json_str)

    time.sleep(2)
