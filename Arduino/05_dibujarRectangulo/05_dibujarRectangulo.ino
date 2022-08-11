#include"TFT_eSPI.h"
TFT_eSPI tft;
 
void setup() {
    tft.begin();
    tft.setRotation(3);
 
    tft.fillScreen(TFT_DARKGREEN); //Fondo verde oscuro
    tft.drawRect(110,70,100,100,TFT_CYAN); //El contorno de un rectángulo cyan de 100x100 iniciando de (110, 70)
    tft.fillRect(111,71,98,98,TFT_MAGENTA); //El relleno del rectángulo magenta, si está en las mismas coordenadas y con el mismo ancho y alto, tapa el contorno
}
void loop() {}
