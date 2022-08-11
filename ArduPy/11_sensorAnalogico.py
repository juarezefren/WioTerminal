from machine import ADC, Pin # Importamos las librerias ADC y PIN
import time
adc = ADC(Pin(13)) # Creamos el convertidos ADC en Pin 13
poten = adc.read() # Leemos los valores de ADC, 0 ~ 1023
while True:
    print("Valor poten: " + str(poten)) # Imprime el valor del potenciometro
    time.sleep(5) # Pausamos por 5 segundos
    poten = adc.read() # Leemos los valores de ADC, 0 ~ 1023
