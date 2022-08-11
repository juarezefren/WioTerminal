from machine import Pin, Map # Importamos las librerias PIN y MAP
import time # Importamos la libreria de tiempo

swAr = Pin(Map.WIO_5S_UP, # Definimos el Pin a usar hacineod uso de Map
       Pin.IN, # Definimos que será un pin de entrada
       Pin.PULL_UP) # Definimos el estado en el que será leído
swAb = Pin(Map.WIO_5S_DOWN,
       Pin.IN,
       Pin.PULL_UP)
swIz = Pin(Map.WIO_5S_LEFT,
       Pin.IN,
       Pin.PULL_UP)
swDe = Pin(Map.WIO_5S_RIGHT,
       Pin.IN,
       Pin.PULL_UP)
swPr = Pin(Map.WIO_5S_PRESS,
       Pin.IN,
       Pin.PULL_UP)

while True:
    time.sleep_ms(200) # Establecemos 200 milisegundos (0.2 segundos) como pausa para la lectura
    if swAr.value() == 0:
        print("Switch hacia arriba")
    elif swAb.value() == 0:
        print("Switch hacia abajo")
    elif swIz.value() == 0:
        print("Switch hacia la izquierda")
    elif swDe.value() == 0:
        print("Switch hacia la derecha")
    elif swPr.value() == 0:
        print("Switch presionado")
