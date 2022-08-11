#include "rpcBLEDevice.h"
#include <BLE2902.h>
#include <TFT_eSPI.h> // Biblioteca específica de hardware
#include <SPI.h>
TFT_eSPI tft = TFT_eSPI(); // Invocar biblioteca personalizada
TFT_eSprite spr = TFT_eSprite(&tft); // Sprite

BLEServer *pServer = NULL;
BLECharacteristic * pTxCharacteristic;
bool deviceConnected = false;
bool oldDeviceConnected = false;
String Value11;

#define SERVICE_UUID "6E400001-B5A3-F393-E0A9-E50E24DCCA9E" // UUID del servicio UART
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"

class MyServerCallbacks: public BLEServerCallbacks { 

    // Mensaje en caso de que se conecte de forma exitosa
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
      spr.fillSprite(TFT_BLACK);
      spr.createSprite(240, 100);
      spr.setTextColor(TFT_WHITE, TFT_BLACK);
      spr.drawString("Mensaje: ", 20, 70);
      spr.setTextColor(TFT_GREEN, TFT_BLACK);
      spr.drawString("Estado: Conectado", 10 , 5);
      spr.pushSprite(0, 0);
    };

    // Mensaje en caso de desconexión
    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
      Serial.print("123123");
      spr.fillSprite(TFT_BLACK);
      spr.createSprite(240, 100);
      spr.setTextColor(TFT_WHITE, TFT_BLACK);
      spr.drawString("Mensaje: ", 20, 70);
      spr.setTextColor(TFT_RED, TFT_BLACK);
      spr.drawString("Estado: desconectado", 10 , 5);
      spr.pushSprite(0, 0);
    }
};

class MyCallbacks: public BLECharacteristicCallbacks {
    // Imprime el mensaje que se envia desde el celular
    void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rxValue = pCharacteristic->getValue();

      if (rxValue.length() > 0) {
        spr.fillSprite(TFT_BLACK);
        spr.setTextColor(TFT_WHITE, TFT_BLACK);
        for (int i = 0; i < rxValue.length(); i++) {
          // Serial.print(rxValue[i]);
          spr.drawString((String)rxValue[i], 10 + i * 15, 0);
          spr.pushSprite(10, 100);
        }
      }
    }
};

void setup() {
  tft.begin();
  tft.init();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  spr.setTextSize(2);

  BLEDevice::init("Wio Terminal");  //Define el nombre del dispositivo

  // Crear el servidor BLE
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Crear una característica BLE
  pTxCharacteristic = pService->createCharacteristic(
                        CHARACTERISTIC_UUID_TX,
                        BLECharacteristic::PROPERTY_NOTIFY | BLECharacteristic::PROPERTY_READ
                      );
  pTxCharacteristic->setAccessPermissions(GATT_PERM_READ);
  pTxCharacteristic->addDescriptor(new BLE2902());

  BLECharacteristic * pRxCharacteristic = pService->createCharacteristic(
      CHARACTERISTIC_UUID_RX,
      BLECharacteristic::PROPERTY_WRITE

                                          );
  pRxCharacteristic->setAccessPermissions(GATT_PERM_READ | GATT_PERM_WRITE);

  pRxCharacteristic->setCallbacks(new MyCallbacks());

  // Iniciar el servicio
  pService->start();

  // Empezar a anunciar
  pServer->getAdvertising()->start();
  spr.fillSprite(TFT_BLACK);
  spr.createSprite(240, 100);
  spr.setTextColor(TFT_WHITE, TFT_BLACK);
  spr.drawString("Estado: Desconectado", 10 , 5);
  spr.drawString("Mensaje: ", 20, 70);
  spr.pushSprite(0, 0);
}

void loop() {
  // Desconectando
  if (!deviceConnected && oldDeviceConnected) {
    delay(500); // dale a la pila bluetooth la oportunidad de preparar las cosas
    pServer->startAdvertising(); // reiniciar la publicidad
    oldDeviceConnected = deviceConnected;
  }
  // Conectando
  if (deviceConnected && !oldDeviceConnected) {
    // hacer cosas aquí en la conexión
    oldDeviceConnected = deviceConnected;
  }
}
