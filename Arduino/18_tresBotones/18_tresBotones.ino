void setup() {
  Serial.begin(115200); // Definimos la velocidad de conexión serial
  pinMode(WIO_KEY_A, INPUT_PULLUP); // Se declara al PIN del Botón A como entrada con valor verdadero
  pinMode(WIO_KEY_B, INPUT_PULLUP); // Se declara al PIN del Botón B como entrada con valor verdadero
  pinMode(WIO_KEY_C, INPUT_PULLUP); // Se declara al PIN del Botón C como entrada con valor verdadero
}
void loop() {
  if (digitalRead(WIO_KEY_A) == LOW) { // Condicionamos el estado del botón A, en caso de ser falso lleva a cabo lo que está dentro
    Serial.println("Botón A presionado"); // Imprimimos en el serial el mensaje
  }
  else if (digitalRead(WIO_KEY_B) == LOW) { // Condicionamos el estado del botón B, en caso de ser falso lleva a cabo lo que está dentro
    Serial.println("Botón B presionado"); // Imprimimos en el serial el mensaje
  }
  else if (digitalRead(WIO_KEY_C) == LOW) { // Condicionamos el estado del botón C, en caso de ser falso lleva a cabo lo que está dentro
    Serial.println("Botón C presionado"); // Imprimimos en el serial el mensaje
  }
  delay(200);
}
