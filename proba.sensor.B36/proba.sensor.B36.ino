/*
 * Script para probar as saídas do sensor de presenza
 * analóxico Allnet 4duino B36
 */

//-------- Parámetros de configuración --------
#define LED 13
#define B36 A0  // Entrada para o PIR analóxico

int espera = 500;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lectura = analogRead(A0);
  Serial.print("Valor sensor: "); Serial.print(lectura);
  Serial.print("\t\tTensión equiv: ");
  Serial.print(map(lectura, 0, 1023, 0, 500)/100);
  Serial.println(" V");
  delay(espera);
}
