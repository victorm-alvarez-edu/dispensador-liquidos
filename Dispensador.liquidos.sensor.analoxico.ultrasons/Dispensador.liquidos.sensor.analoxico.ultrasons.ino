/*
 * Script que controla un dispensador mediante 
 * un sensor analóxico de ultrasóns (HC-SR04).
 * 
 * Cando o sensor analóxico detecta presenza,
 * activa durante un periodo de tempo regulable
 * un relé que á súa vez alimenta ao motor que
 * acciona o mecanismo dispensador.
 *
 * Mentres o dispensador estea activo, o sensor quedará
 * deshabilitado. Quedará dispoñible novamente unha vez 
 * pase o tempo usado polo dispensador, máis un tempo de
 * espera regulable no código do programa.
 */

//-------- Parámetros de configuración --------
#define TRIGGER 9     // Emisión de ultrasóns
#define ECHO 10       // Recepción de ultrasóns
#define RELAY 8

// Macro para calcular a distancia (en cm)
#define calcDist(t) t*0.017

// Variables para o sensor de ultrasóns
float tempo, distancia;
float ti, tf;      // Tempos de envío e recepción do pulso
int echo;
float lectura = -1; // Valor da distancia (cm) medida polo sensor
float dMin = 2.0;  // Distancia mínima para detectar presenza (cm)
float dMax = 12.5;  // Distancia máxima para detectar presenza (cm)
// por fóra do rango [dMin, dMax], o dispensador non actúa

// Variables para a lóxica do dispensador
int tDispensador = 3;  // Tempo en segundos que está ON o dispensador
int tEspera = 10;      // Tempo en segundos de espera antes de suministrar
unsigned long int tInicial = 0; // Importante: unsigned long int evita desbordamento
bool tempoCumplido = true;
bool sensor = false;         // Estado do sensor de presenza
int espera = 600;

// -------- Declaración de E/S --------
void setup() {
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, LOW);
  tInicial = millis();
  Serial.begin(9600);
}

// -------- Lóxica do dispensador --------
void loop() {
  // Lectura do sensor de presenza
  lectura = medirDist();
  sensor = (lectura <= dMax) && (lectura >= dMin);  // Comprobamos que está dentro do rango
  // Se o sensor está activo e pasou tempo suficiente
  if(sensor && tempoCumplido) {
    digitalWrite(RELAY, HIGH);  // ... activa dispensador
    tInicial = millis();        // ... empeza temporización
  }
  //Se pasou o tempo que necesita o mecanismo dispensador...
  if(millis() - tInicial >= tDispensador * 1000) {
    digitalWrite(RELAY, LOW);  //  Apagamos dispensador
  }
  // Engadimos unha pequena espera antes de habilitar dispensador
  tempoCumplido = millis() - tInicial >= (tDispensador + tEspera) * 1000;
  
  delay(espera);
}

// Función auxiliar para medir a distancia a partir dos tempos dos pulsos
float medirDist() {
  // Enviamos un pulso co HC-SR04
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
  echo = digitalRead(ECHO);
  ti = micros();
  while(echo == LOW) {
    echo = digitalRead(ECHO);
  }
  while(echo == HIGH) {
    echo = digitalRead(ECHO);
    tf = micros();
  }
  tempo = tf - ti;
  tempo /= 2;
  return(calcDist(tempo));
}


