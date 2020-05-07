/*
 * Script que controla un dispensador mediante 
 * un sensor dixital.
 * 
 * Cando o sensor dixital detecta presenza,
 * activa durante un periodo de tempo regulable
 * un relé que á súa vez alimenta ao motor que
 * acciona o mecanismo dispensador.
 *
 * Empregamos un sensor PIR para simulación, pero 
 * valería calquera outro sensor con saída dixital. 
 * P.ex. pódese usar un sensor IR de distancia.
 * Como saída emprégase un LED, aínda que no pin
 * correspondente débese conectar a entrada dun relé.
 *
 * Mentres o dispensador estea activo, o sensor quedará
 * deshabilitado. Quedará dispoñible novamente unha vez 
 * pase o tempo usado polo dispensador, máis un tempo de
 * espera regulable no código do programa.
 */

//-------- Parámetros de configuración --------
#define PIR 13
#define RELAY 8

int tDispensador = 1000;  // Tempo que está ON o dispensador
int tEspera = 200;        // Tempo de espera antes de suministrar
unsigned long int tInicial = 0;
bool tempoCumplido = true;
bool pir = false;         // Estado do sensor de presenza

// -------- Declaración de E/S --------
void setup() {
  pinMode(PIR, INPUT);
  pinMode(RELAY, OUTPUT);
  Serial.begin(9600);
}

// -------- Lóxica do dispensador --------
void loop() {
  // Lectura do sensor de presenza
  pir = digitalRead(PIR);
  // Se o sensor está activo e pasou tempo suficiente
  if(pir && tempoCumplido) {  
    digitalWrite(RELAY, HIGH);  // ... activa dispensador
    tInicial = millis();        // ... empeza temporización
  }
  //Se pasou o tempo que necesita o mecanismo dispensador...
  else if(millis() - tInicial >= tDispensador) {
    digitalWrite(RELAY, LOW);  //  Apagamos dispensador
    tInicial = 0;              //  Reiniciamos tempo actual
  }
  // Engadimos unha pequena espera antes de habilitar dispensador
  tempoCumplido = millis() - tInicial >= tDispensador + tEspera;
}
