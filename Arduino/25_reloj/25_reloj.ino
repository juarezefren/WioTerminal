#include "RTC_SAMD51.h" // Importamos la librería que interactúa con el Wio
#include "DateTime.h" // Importamos la librería de tiempo

RTC_SAMD51 rtc; // Creamos el objeto de la librería del Wio
void setup()
{
  rtc.begin(); // Iniciamos el objeto del Wio

  Serial.begin(115200); // Definimos la velocidad de conexión

  while (!Serial) // Hacemos una espera
  {
    ;
  }

  DateTime now = DateTime(F(__DATE__), F(__TIME__)); // Importamos la fecha y la hora según el equipo
  Serial.println("¡Fecha ajustada!");
  rtc.adjust(now); // Se realiza el ajuste de la fecha y la hora

  now = rtc.now(); // Se actualiza

  Serial.print(now.year(), DEC); // Se imprime el año
  Serial.print('/');
  Serial.print(now.month(), DEC); // Se imprime el mes
  Serial.print('/');
  Serial.print(now.day(), DEC); // Se imprime el día
  Serial.print(" ");
  Serial.print(now.hour(), DEC); // Se imprime la hora
  Serial.print(':');
  Serial.print(now.minute(), DEC); // Se imprime los minutos
  Serial.print(':');
  Serial.print(now.second(), DEC); // Se imprimen los segundos
  Serial.println();

  DateTime alarm = DateTime(now.year(), now.month(), now.day(), now.hour(), now.minute(), now.second() + 15); // Se establece un objeto alarma a la hora más 15 segundos

  rtc.setAlarm(0, alarm); // Se habilita la alarma con el objeto anteriormente creado
  rtc.enableAlarm(0, rtc.MATCH_HHMMSS); // Y se habilita para todos los dias

  rtc.attachInterrupt(alarmMatch); // Devuelve la alarma cuando las horas coinciden y llama a una función

}

void loop()
{
}

void alarmMatch(uint32_t flag) // En caso de que haya coincidencia de hora, esta función corre e imprime un mensaje de la coincidencia, junto a la fecha y hora
{

  Serial.println("Alarma Coincide!");
  DateTime now = rtc.now();
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
}
