from machine import DAC, Pin, Map
import time

buz = DAC(Pin(Map.WIO_BUZZER))

while True:
    buz.write(127)
    time.sleep(1)
    buz.write(0)
    time.sleep(1)
