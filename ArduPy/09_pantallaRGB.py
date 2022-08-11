from machine import LCD # Importamos la libreria de LCD
import time
 
lcd = LCD() # Iniciamos la LCD y encendemos el fondo

while True: # En ciclo cambia entre los colores R-G-B
    lcd.fillScreen(lcd.color.RED) # Enciende toda la pantalla de color rojo
    time.sleep(1)
    lcd.fillScreen(lcd.color.GREEN) # Enciende toda la pantalla de color verde
    time.sleep(1)
    lcd.fillScreen(lcd.color.BLUE) # Enciende toda la pantalla de color azul
    time.sleep(1)
