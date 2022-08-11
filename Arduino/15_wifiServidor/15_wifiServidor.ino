#include <rpcWiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

#define LED_BUILTIN 2   // LED de prueba

// Definimos credenciales para el punto de acceso
const char* ssid = "Wio Terminal";
const char* password = "102991299";
int estado = 0;

WiFiServer server(80);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);
  while (!Serial); // Wait for Serial to be ready
  delay(1000);
  Serial.println();
  Serial.println("Configurando el punto de acceso...");

  // Puede remover el parametro "password" si se desea que la red sea abierta
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  /*
     Recuerda la dirección IP, será usada como cliente (en el navegador)
  */
  Serial.print("Direccón IP del Punto de Acceso: ");
  Serial.println(myIP);
  server.begin();

  Serial.println("Servidor iniciado");
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  WiFiClient client = server.available();   // Escuchar a los clientes entrantes

  if (client) {                             // Si tienes un cliente,
    Serial.println("Nuevo Cliente.");           // imprimir un mensaje por el puerto serie
    String currentLine = "";                // hacer una cadena para contener los datos entrantes del cliente
    while (client.connected()) {            // Bucle mientras el cliente está conectado
      if (client.available()) {             // Si hay bytes para leer del cliente,
        digitalWrite(LED_BUILTIN, estado);
        char c = client.read();             // leer un byte, entonces
        Serial.write(c);                    // imprimirlo en el monitor serie
        if (c == '\n') {                    // si el byte es un carácter de nueva línea

          // si la línea actual está en blanco, tiene dos caracteres de nueva línea seguidos.
          // ese es el final de la solicitud HTTP del cliente, así que envíe una respuesta:
          if (currentLine.length() == 0) {
            // Los encabezados HTTP siempre comienzan con un código de respuesta (por ejemplo, HTTP/1.1 200 OK)
            // y un tipo de contenido para que el cliente sepa lo que viene, luego una línea en blanco:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // el contenido de la respuesta HTTP sigue al encabezado:
            client.print("Pica <a href=\"/H\">aqui</a> para ENCENDER el LED.<br>");
            client.print("Pica <a href=\"/L\">aqui</a> para APAGAR el LED.<br>");

            // La respuesta HTTP termina con otra línea en blanco:
            client.println();
            // salir del ciclo while:
            break;
          } else {    // si tiene una línea nueva, borre la línea actual:
            currentLine = "";
          }
        } else if (c != '\r') {  // si tiene algo más que un carácter de retorno,
          currentLine += c;      // agréguelo al final de la línea actual
        }

        // Verifique si la solicitud del cliente fue "GET /H" o "GET /L":
        if (currentLine.endsWith("GET /H")) {
          digitalWrite(LED_BUILTIN, HIGH);               // GET /H enciende el LED
          estado = 1;
        }
        if (currentLine.endsWith("GET /L")) {
          digitalWrite(LED_BUILTIN, LOW);                // GET /L apaga el LED
          estado = 0;
        }
      }
    }
    // Cierre de conexión:
    client.stop();
    Serial.println("Cliente Desconectado.");
  }
}
