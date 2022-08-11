from machine import LCD # Importamos la libreria de LCD
 
lcd = LCD() # Iniciamos la LCD y encendemos el fondo
lcd.fillScreen(lcd.color.RED) # Enciende toda la pantalla de color rojo
lcd.drawFastHLine(0,120,320,lcd.color.BLACK) # Una línea horizontal negra que inicia en (0, 120)
lcd.drawFastVLine(160,0,240,lcd.color.BLACK) # Una línea vertical blanca que inicia en (160, 0)
