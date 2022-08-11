from machine import LCD # Importamos la libreria de LCD
 
lcd = LCD() # Iniciamos la LCD y encendemos el fondo
lcd.fillScreen(lcd.color.RED) # Enciende toda la pantalla de color rojo
lcd.drawCircle(160,120,50,lcd.color.BLACK) # Un círculo negro con origen en (160, 120)
