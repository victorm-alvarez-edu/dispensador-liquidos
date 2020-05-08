/*
 * Script para probar os estados do relé.
 *
 * O relé dispoñible ten dous LEDs de estado,
 * vermello (sensor alimentado) e verde.
 * 
 * Cando o verde encende, o relé conmuta, pero
 * non queda claro se ten o optoacoplador alimentado
 * ou non. Para deixar o sistema nun estado normal
 * de 'non consumo' a fin de aforrar batería.
 */

//-------- Parámetros de configuración --------
#define RELAY 8

int espera 5000;

// -------- Declaración de E/S --------
void setup() {
  pinMode(RELAY, OUTPUT);
  Serial.begin(9600);
}

// -------- Lóxica do relé --------
void loop() {
  digitalWrite(RELAY, LOW);
  Serial.println("Relé OFF");
  delay(espera);
  digitalWrite(RELAY, HIGH);
  Serial.println("Relé ON");
  delay(espera);
}

/*
 * Nota:
 * Efectivamente, o meu relé pon en ON o LED verde
 * cando se escrebe LOW na súa entrada dixital.
 * Vai a revés de como sería de esperar poLa cor do LED.
 */
