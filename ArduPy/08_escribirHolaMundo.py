from machine import LCD # Importamos la libreria de LCD
import time
 
lcd = LCD() # Iniciamos la LCD y encendemos el fondo

lcd.fillScreen(lcd.color.RED) # Llenamos el fondo de la LCD en rojo

lcd.setTextColor(lcd.color.BLACK) # Define el color del texto
lcd.setTextSize(1) # Define tamaño del texto a 1
lcd.drawString("Hola Mundo",0,0) # Imprime texto desde (0, 0)
lcd.setTextSize(2) # Define tamaño del texto a 2
lcd.drawString("Hola Mundo",0,10) # Imprime texto desde (0,10)
