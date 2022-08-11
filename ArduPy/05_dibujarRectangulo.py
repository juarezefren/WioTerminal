from machine import LCD # Importamos la libreria de LCD
 
lcd = LCD() # Iniciamos la LCD y encendemos el fondo
lcd.fillScreen(lcd.color.DARKGREEN) # Enciende toda la pantalla de color verde oscuro
lcd.drawRect(110,70,100,100,lcd.color.CYAN) # El contorno de un rectángulo cyan de 100x100 iniciando de (110, 70)
lcd.fillRect(111,71,98,98,lcd.color.MAGENTA) # El relleno del rectángulo magenta, si está en las mismas coordenadas y con el mismo ancho y alto, tapa el contorno
