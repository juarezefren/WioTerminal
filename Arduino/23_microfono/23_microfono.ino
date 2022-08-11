void setup() {
  pinMode(WIO_MIC, INPUT); // Seleccionamos el PIN del Microfono y lo marcamos como dispositivo de entrada
  Serial.begin(115200); // Marcamos la velocidad de transmisión de datos
}

void loop() {
  int val = analogRead(WIO_MIC); // Damos el valor del sensor a una variable
  Serial.println("Volumen de entrada:" + String((val*100)/1024)); // Imprimimos el valor de la lectura en una escala del 0 al 100
  delay(1000); // Hacemos una pausa de 1000 milisegundos (1 segundo)
}
