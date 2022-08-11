from machine import ADC, Pin, Map # Importamos las librerias ADC y PIN
import time
adc = ADC(Pin(Map.WIO_MIC)) # Creamos el convertidos ADC en pin del sensor del Wio (Pin)
vol = adc.read() # Leemos los valores de ADC, 0 ~ 1023
while True:
    print("Volumen de entrada: " + str(((vol*100)/1024))) # Imprime el valor del microfono
    time.sleep(1) # Pausamos por 1 segundos
    vol = adc.read() # Leemos los valores de ADC, 0 ~ 1023
