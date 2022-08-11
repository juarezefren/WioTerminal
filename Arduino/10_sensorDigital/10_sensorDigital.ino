#include"TFT_eSPI.h"
#include "DHT.h" //Llamamos a la libreria
TFT_eSPI tft;
DHT dht(D0,DHT11); //Definimos el PIN a usar y el sensor
 
void setup() {
  tft.begin();
  dht.begin(); //Inicializamos el sensor
  tft.setRotation(3);
 
  tft.fillScreen(TFT_WHITE); //Fondo blanco 
}

void loop() {
  float temp = dht.readTemperature(); //Leemos la temperatura y guardamos el dato en una variable float
  float hume = dht.readHumidity(); //Leemos la humedad y guardamos el dato en una variable float
  tft.setTextSize(2);
  tft.drawString("Temperatura: ",10,10);
  tft.drawString(String(temp),10,30); //Imprimimos en el Serial el valor de la temperatura
  tft.drawString("Humedad: ",10,50);
  tft.drawString(String(hume),10,70); //Imprimimos en el Serial el valor de la humedad
  delay(5000); //Realizamos una pausa de 5000 milisegundos (5 segundos)
}
