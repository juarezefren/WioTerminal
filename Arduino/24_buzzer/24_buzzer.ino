void setup() {
  pinMode(WIO_BUZZER, OUTPUT); // Habilitamos el zumbador y lo establecemos como salida
}

void loop() {
  analogWrite(WIO_BUZZER, 128); // Enviamos un valor que emita el sonido
  delay(1000); // Pausa de un segundo
  analogWrite(WIO_BUZZER, 0); // Enviamos un valor para un silencio
  delay(1000); // Pausa de un segundo
}
