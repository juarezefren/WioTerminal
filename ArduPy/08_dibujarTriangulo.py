from machine import LCD # Importamos la libreria de LCD
 
lcd = LCD() # Iniciamos la LCD y encendemos el fondo
lcd.fillScreen(lcd.color.RED) # Enciende toda la pantalla de color rojo
lcd.drawTriangle(160,70,60,170,260,170,lcd.color.BLACK) # Un triángulo con puntos en (160, 70), (60, 170) y (260, 170)