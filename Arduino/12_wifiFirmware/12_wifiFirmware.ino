#include "rpcWiFi.h" // Importar la libreria 
 
void setup() {
    Serial.begin(115200);
    while(!Serial); // Espera a que se abra el Monitor Serial
    Serial.printf("RTL8720 Firmware Version: %s", rpc_system_version());
}
 
void loop() {
}
