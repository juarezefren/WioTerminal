#include <SPI.h>
#include <Seeed_FS.h>
#include "SD/Seeed_SD.h"

File myFile;

void setup() {
  Serial.begin(115200);
  while (!Serial) {
  }
  Serial.print("Inicializando tarjeta SD...");
  if (!SD.begin(SDCARD_SS_PIN, SDCARD_SPI)) {
    Serial.println("Inicialización fallida!");
    while (1);
  }
  Serial.println("Inicialización hecha.");

  // Abrir el archivo. tenga en cuenta que solo se puede abrir un archivo a la vez,
  // así que tienes que cerrar este antes de abrir otro.
  myFile = SD.open("test.txt", FILE_WRITE);

  // si el archivo se abrió bien, se escribirá:
  if (myFile) {
    Serial.print("Escribiendo en test.txt...");
    myFile.println("probando 1, 2, 3.");
    // Cerrar el archivo:
    myFile.close();
    Serial.println("Escritura terminada. Hecho!");
  } else {
    // si el archivo no se abre, imprime un error:
    Serial.println("Error abriendo test.txt");
  }

  // volver a abrir el archivo para leer:
  myFile = SD.open("test.txt", FILE_READ);
  if (myFile) {
    Serial.println("test.txt:");
    Serial.println("*****************INICIO*********************");
    // leer del archivo hasta que no haya nada más en él:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    Serial.println("*******************FIN**********************");
    // cerrar el archivo:
    myFile.close();
  } else {
    // si el archivo no se abre, imprime un error:
    Serial.println("Error abriendo test.txt");
  }
}

void loop() {

}
