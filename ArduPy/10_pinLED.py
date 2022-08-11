from machine import Pin, Map # Importamos la libreria de Pin, Map
import time

LED = Pin(Pin(13), Pin.OUT)

while True:
    LED.on()
    time.sleep(1)
    LED.off()
    time.sleep(1)