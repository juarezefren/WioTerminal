#include"TFT_eSPI.h"
TFT_eSPI tft;
 
void setup() {
    tft.begin();
    tft.setRotation(3);
 
    tft.fillScreen(TFT_RED); //usamos un fondo blanco
    tft.drawPixel(4,7,TFT_BLACK); //dibujamos un pixel negro en (4,7)
}
 
void loop() {}
