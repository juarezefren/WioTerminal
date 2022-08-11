#include"TFT_eSPI.h"
TFT_eSPI tft;
 
void setup() {
    tft.begin();
    tft.setRotation(3);
 
    tft.fillScreen(TFT_RED); //Fondo rojo
    tft.drawTriangle(160,70,60,170,260,170,TFT_BLACK);
    // Un triángulo con puntos en (160, 70), (60, 170) y (260, 170)
}
 
void loop() {}
