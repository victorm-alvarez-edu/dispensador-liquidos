//-------- Parámetros de configuración --------
#define RELAY 8

// -------- Declaración de E/S --------
void setup() {
  pinMode(RELAY, OUTPUT);
  Serial.begin(9600);
}

// -------- Lóxica do dispensador --------
void loop() {
  digitalWrite(RELAY, LOW);
  Serial.println("Relé OFF");
  delay(5000);
  digitalWrite(RELAY, HIGH);
  Serial.println("Relé ON");
  delay(5000);
}
