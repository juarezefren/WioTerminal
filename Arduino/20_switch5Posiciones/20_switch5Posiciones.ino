void setup() {
  Serial.begin(115200);
  pinMode(WIO_5S_UP, INPUT_PULLUP);
  pinMode(WIO_5S_DOWN, INPUT_PULLUP);
  pinMode(WIO_5S_LEFT, INPUT_PULLUP);
  pinMode(WIO_5S_RIGHT, INPUT_PULLUP);
  pinMode(WIO_5S_PRESS, INPUT_PULLUP);
}
 
void loop() {
   if (digitalRead(WIO_5S_UP) == LOW) {
    Serial.println("Switch hacia arriba");
   }
   else if (digitalRead(WIO_5S_DOWN) == LOW) {
    Serial.println("Switch hacia abajo");
   }
   else if (digitalRead(WIO_5S_LEFT) == LOW) {
    Serial.println("Switch hacia la izquierda");
   }
   else if (digitalRead(WIO_5S_RIGHT) == LOW) {
    Serial.println("Switch hacia la derecha");
   }
   else if (digitalRead(WIO_5S_PRESS) == LOW) {
    Serial.println("Switch presionado");
   }
   delay(200);
}
