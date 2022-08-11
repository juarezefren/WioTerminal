#include"TFT_eSPI.h"
TFT_eSPI tft;
 
void setup() {
  tft.begin();
  tft.setRotation(3);
 
  tft.fillScreen(TFT_RED); //Fondo rojo
 
  tft.setTextColor(TFT_BLACK); // Define el color del texto
  tft.setTextSize(1); // Define tamaño del texto a 1
  tft.drawString("Hola Mundo", 0, 0); // Imprime texto desde (0, 0)
  tft.setTextSize(2); // Define tamaño del texto a 2
  tft.drawString("Hola Mundo", 0, 10); // Imprime texto desde (0,10)
}
 
void loop() {} 
