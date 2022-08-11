#include"TFT_eSPI.h" // Importamos la libreria del LCD_TFT
TFT_eSPI tft; // Creamos el objeto de la libreria del LCD_TFT

void setup() {
  tft.begin(); // Inicializamos el objeto
  tft.setRotation(3); // Decimos que rotación será
  Serial.begin(115200); // Definimos la velocidad de conexión serial
  pinMode(WIO_KEY_A, INPUT_PULLUP); // Se declara al PIN del Botón A como entrada con valor verdadero
  pinMode(WIO_KEY_B, INPUT_PULLUP); // Se declara al PIN del Botón B como entrada con valor verdadero
  pinMode(WIO_KEY_C, INPUT_PULLUP); // Se declara al PIN del Botón C como entrada con valor verdadero
}
void loop() {
  if (digitalRead(WIO_KEY_A) == LOW) { // Condicionamos el estado del botón, en caso de ser falso lleva a cabo lo que está dentro
    tft.fillScreen(TFT_RED); // Ponemos la pantalla en rojo
  }
  else if (digitalRead(WIO_KEY_B) == LOW) { // Condicionamos el estado del botón, en caso de ser falso lleva a cabo lo que está dentro
    tft.fillScreen(TFT_GREEN); // Ponemos la pantalla en verde
  }
  else if (digitalRead(WIO_KEY_C) == LOW) { // Condicionamos el estado del botón, en caso de ser falso lleva a cabo lo que está dentro
    tft.fillScreen(TFT_BLUE); // Ponemos la pantalla en azul
  }
  delay(100); // Pausamos 100 milisegundos (0.1 segundos)
}
