from machine import Pin, Map, LCD # Importamos las librerias PIN, MAP, LCD
import time # Importamos la libreria de tiempo

lcd = LCD() # Iniciamos la LCD y encendemos el fondo

btnA = Pin(Map.WIO_KEY_A, # Definimos el Pin a usar hacineod uso de Map
       Pin.IN, # Definimos que será un pin de entrada
       Pin.PULL_UP) # Definimos el estado en el que será leído
btnB = Pin(Map.WIO_KEY_B,
       Pin.IN,
       Pin.PULL_UP)
btnC = Pin(Map.WIO_KEY_C,
       Pin.IN,
       Pin.PULL_UP)

while True:
    time.sleep_ms(200) # Establecemos 200 milisegundos (0.2 segundos) como pausa para la lectura
    if btnA.value() == 0:
        lcd.fillScreen(lcd.color.RED)
    elif btnB.value() == 0:
        lcd.fillScreen(lcd.color.GREEN)
    elif btnC.value() == 0:
        lcd.fillScreen(lcd.color.BLUE)
