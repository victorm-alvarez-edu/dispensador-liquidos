
/*
 * Script para probar os estados do sensor IR FC51.
 * 
 * O sensor dispón de dous LEDs de estado verdes
 * na placa. Un deles ponse en ON can do se alimenta
 * o sensor. O outro ponse en ON cando o sensor
 * detecta presenza unha vez superado o umbral
 * regulado co potenciómetro (tamén en placa).
 * 
 * Queremos saber que saída dá ao activarse o sensor.
 * Supoñemos que LOW ao detectar presenza.
 */

//-------- Parámetros de configuración --------
#define PIR 13

int espera 5000;

// -------- Declaración de E/S --------
void setup() {
  pinMode(PIR, INPUT);
  Serial.begin(9600);
}

// -------- Lectura do IR FC51 --------
void loop() {
  int pir = !digitalRead(PIR);
  Serial.print("Valor PIR: "); Serial.println(pir);
  delay(espera);
}

/*
 * Nota:
 * Efectivamente, o sensor dá saída activa (HIGH)  
 * continuamente e conmuta a LOW cando detecta
 * presenza.
 */
