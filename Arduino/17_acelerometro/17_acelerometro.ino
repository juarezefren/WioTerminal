#include"LIS3DHTR.h" // Importamos la libreria
LIS3DHTR<TwoWire> lis; // Creamos el objero
 
void setup() {
  Serial.begin(115200); // Definimos la velocidad de transmisión de datos
  lis.begin(Wire1); // Iniciamos al acelerometro
 
  if (!lis) { // Si no está funcional marcará error
    Serial.println("ERROR");
    while(1);
  }
  lis.setOutputDataRate(LIS3DHTR_DATARATE_25HZ); //Tasa de datos de salida
  lis.setFullScaleRange(LIS3DHTR_RANGE_2G); //Confugura el rango de escala 2g
}
 
void loop() {
  /* Se definen variables que almacenen la posición y se leen posteriormente los valores */
  float x_values, y_values, z_values;
  x_values = lis.getAccelerationX();
  y_values = lis.getAccelerationY();z
  z_values = lis.getAccelerationZ();

  /* Se imprimen los valores de las posiciones */
  Serial.print("X: "); Serial.print(x_values);
  Serial.print(" Y: "); Serial.print(y_values);
  Serial.print(" Z: "); Serial.print(z_values);
  Serial.println();
  delay(1000); // Se hace una pausa de 1000 milisegundos (1 segundo)
}
