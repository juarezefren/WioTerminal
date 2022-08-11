#include"TFT_eSPI.h"
TFT_eSPI tft;
 
void setup() {
    tft.begin();
    tft.setRotation(3);
 
    tft.fillScreen(TFT_RED); //Fondo rojo
    tft.drawFastHLine(0,120,320,TFT_BLACK); //Una línea horizontal negra que inicia en (0, 120)
    tft.drawFastVLine(160,0,240,TFT_BLACK); // Una línea vertical blanca que inicia en (160, 0)
}
 
void loop() {}
