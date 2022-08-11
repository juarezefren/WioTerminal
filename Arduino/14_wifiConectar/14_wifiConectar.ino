#include "rpcWiFi.h" // Importamos la libreria
 
const char* ssid = "redPrueba"; // Escribimos el nombre de la red a conectarnos
const char* password =  "contrasenia"; // Escribimos la contraseña de la red a conertarnos
 
void setup() {
    Serial.begin(115200);
    while(!Serial); // Espera al monitor serial
 
    WiFi.mode(WIFI_STA); // Establecemos el adaptador como Estación
    WiFi.disconnect(); // Desconectamos el adaptador de cualquier red en caso de estar conectada
 
    Serial.println("Conectando al WiFi..");
    WiFi.begin(ssid, password); // Usa el nombre y contraseña de red para intentar conectarse
 
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Conectando al WiFi..");
        WiFi.begin(ssid, password); // Usa el nombre y contraseña de red para intentar conectarse
    }
    Serial.println("Conectado a la red WiFi");
    Serial.print("Dirección IP: ");
    Serial.println (WiFi.localIP()); // Imprime la dirección IP del Wio Terminal en la red
    }
 
void loop() {
 
}
