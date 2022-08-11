#include"TFT_eSPI.h" // Importamos la librería 
TFT_eSPI tft; // Iniciamos la librería como un objeto 
 
void setup() {
    tft.begin(); // Iniciamos el objeto
    tft.setRotation(3); // Establecemos el sentido de la rotación
 
    tft.fillScreen(TFT_RED); // Enciende toda la pantalla de color rojo
}
 
void loop() {
 
}
