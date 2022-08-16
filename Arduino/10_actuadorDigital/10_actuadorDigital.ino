#include <Servo.h>
Servo myservo;
 
int pos = 0;
 
void setup() {
  myservo.attach(D0, 550, 2550); // Definimos el pin de salida y definimos la señal enviada
  myservo.write(pos);
  delay(1000);
}
 
void loop() {
  for (pos = 0; pos <= 180; pos += 1) {
    // En pasos de uno
    myservo.write(pos);
    delay(15);
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(15);
  }
}
