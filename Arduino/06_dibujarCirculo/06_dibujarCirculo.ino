#include"TFT_eSPI.h"
TFT_eSPI tft;
 
void setup() {
    tft.begin();
    tft.setRotation(3);
 
    tft.fillScreen(TFT_RED); //Fondo rojo
    tft.drawCircle(160,120,50,TFT_BLACK); //Un círculo negro con origen en (160, 120)
}
 
void loop() {}
