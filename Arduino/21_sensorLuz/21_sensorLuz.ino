void setup() {
  pinMode(WIO_LIGHT, INPUT); // Seleccionamos el pin de entrada del sensor de luz
  Serial.begin(115200); // Establecemos la velocidad de conexión
}
 
void loop() {
   int light = analogRead(WIO_LIGHT); // Leemos el valor del sensor de luz
   Serial.print("Luminosidad: "); // Imprimimos el mensaje
   Serial.println(light); // Imprimimos el valor
   delay(2000); // Pausamos por 2000 milisegundos (2 segundos) al programa
}
