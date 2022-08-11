from machine import LCD # Importamos la libreria de LCD
 
lcd = LCD() # Iniciamos la LCD y encendemos el fondo
lcd.fillScreen(lcd.color.RED) # Enciende toda la pantalla de color rojo
lcd.drawEllipse(160,120,50,100,lcd.color.BLACK) # Una elipse negra con origen en (160, 120) con un radio horizontal de 50, y un radio vertical de 100
