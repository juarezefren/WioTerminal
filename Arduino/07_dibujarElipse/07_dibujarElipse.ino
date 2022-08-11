#include"TFT_eSPI.h"
TFT_eSPI tft;
 
void setup() {
    tft.begin();
    tft.setRotation(3);
 
    tft.fillScreen(TFT_RED); //Fondo rojo
    tft.drawEllipse(160,120,50,100,TFT_BLACK); 
    // Una elipse negra con origen en (160, 120) con un radio horizontal de 50, y un radio vertical de 100
}
void loop() {}
