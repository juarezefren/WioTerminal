#include <IRLibSendBase.h> // Incluimos la librería base
#include <IRLib_P02_Sony.h> 
#include <IRLibCombo.h> // Incluimos esta librería
 
IRsend mySender;
 
void setup() {
  Serial.begin(9600);
  delay(2000); while (!Serial); //Pausamos
  Serial.println(F("Cada que tu presiones el botón Enviar, la señal será enviada."));
}
 
void loop() {
  if (Serial.read() != -1) {
    mySender.send(SONY,0xa8bca, 20);//Señal de encendido Sony DVD A8BCA, de 20 bits
    Serial.println(F("Señal enviada!."));
  }
}
