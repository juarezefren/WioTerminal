#include"TFT_eSPI.h"
TFT_eSPI tft;
 
void setup() {
    tft.begin();
    tft.setRotation(3);
 
    tft.fillScreen(TFT_RED); //Fondo de color rojo
    tft.drawLine(0,0,160,120,TFT_BLACK); //Línea negra de (0,0) a (160,120)
}
 
void loop() {}
