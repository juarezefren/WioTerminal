from machine import LCD # Importamos la libreria de LCD
 
lcd = LCD() # Iniciamos la LCD y encendemos el fondo
lcd.fillScreen(lcd.color.RED) # Enciende toda la pantalla de color rojo
lcd.drawLine(0,0,160,120,lcd.color.BLACK) # Línea negra de (0,0) a (160,120)
