from machine import Pin, Map # Importamos las librerias PIN y MAP
import time # Importamos la libreria de tiempo

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
        print("Botón A presionado")
    elif btnB.value() == 0:
        print("Botón B presionado")
    elif btnC.value() == 0:
        print("Botón C presionado")
