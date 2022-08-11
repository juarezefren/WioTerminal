void setup() {
  Serial.begin(9600); // Definimos la velocidad de transmisión de datos
}

void loop() {
  int poten = analogRead(A0); // Leemos el valor del potenciometro
  Serial.println("Valor poten: " + String(poten)); // Imprimimos el valor del potenciometro
  delay(5000); // Pausamos por 5000 milisegundos (5 segundos)
}
