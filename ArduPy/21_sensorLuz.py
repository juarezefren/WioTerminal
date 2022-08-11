from machine import ADC, Pin, Map # Importamos las librerias ADC y PIN
import time
adc = ADC(Pin(Map.WIO_LIGHT)) # Creamos el convertidos ADC en pin del sensor del Wio (Pin)
lumi = adc.read() # Leemos los valores de ADC, 0 ~ 1023
while True:
    print("Luminosidad: " + str(lumi)) # Imprime el valor del sensor de luz
    time.sleep(2) # Pausamos por 2 segundos
    lumi = adc.read() # Leemos los valores de ADC, 0 ~ 1023
