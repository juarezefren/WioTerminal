#include "rpcWiFi.h" // Importamos la libreria
 
void setup() {
    Serial.begin(115200);
    while(!Serial); // Espera al monitor serial abra
    delay(1000);
    WiFi.mode(WIFI_STA); // Establecemos el adaptador como Estación
    WiFi.disconnect(); // Desconectamos el adaptador de cualquier red en caso de estar conectada
    delay(100);
 
    Serial.println("Configuración hecha");
}
 
void loop() {
    Serial.println("Iniciando Escaneo");
    int n = WiFi.scanNetworks(); // WiFi.scanNetworks regresa el número de redes encontradas
    Serial.println("Escaneo hecho");
    if (n == 0) {
        Serial.println("No se encontraron redes");
    } else {
        Serial.print(n);
        Serial.println("Redes encontradas");
        for (int i = 0; i < n; ++i) {
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i)); // Imprime el nombre de la red
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i)); // Imprime la potencia de la señal
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*"); // Identifica si una red es abierta (" ") o tiene autenticación ("*")
            delay(10);
        }
    }
    Serial.println("");

    delay(5000); // Espera un poco para escanear otra vez
}
