#include"TFT_eSPI.h"
TFT_eSPI tft;
 
void setup() {
  tft.begin();
  tft.setRotation(3);
}
 
void loop() {
    //En ciclo cambia entre los colores R-G-B
    tft.fillScreen(TFT_RED);
    delay(1000);
    tft.fillScreen(TFT_GREEN);
    delay(1000);
    tft.fillScreen(TFT_BLUE);
    delay(1000);
}
