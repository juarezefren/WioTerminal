#define BUZZER_PIN WIO_BUZZER // Definimos un PIN
 
int length = 15; // Número de notas
char notes[] = "ccggaagffeeddc "; // Notas
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 }; // Beats
int tempo = 300; // Tempo
 
void setup() {
    pinMode(BUZZER_PIN, OUTPUT); // Definimos al Pin del zumbador como salida
}
 
void loop() {
    for(int i = 0; i < length; i++) { // Hacemos un ciclo con la longitud de las notas
        if(notes[i] == ' ') {
            delay(beats[i] * tempo);
        } else {
            playNote(notes[i], beats[i] * tempo); // Se envia la nota, el beat y el tempo a la función que reproduce una nota
        }
        delay(tempo / 2); // Pausa entre notas
    }
 
}
 
// Reproduce un tono
void playTone(int tone, int duration) {
    for (long i = 0; i < duration * 1000L; i += tone * 2) {
        digitalWrite(BUZZER_PIN, HIGH);
        delayMicroseconds(tone);
        digitalWrite(BUZZER_PIN, LOW);
        delayMicroseconds(tone);
    }
}

// Reproduce la nota
void playNote(char note, int duration) {
    char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
    int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
 
    // Reproduce el tono correspondiente al nombre del mismo
    for (int i = 0; i < 8; i++) {
        if (names[i] == note) {
            playTone(tones[i], duration);
        }
    }
}
