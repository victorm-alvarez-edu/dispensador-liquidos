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

int tDispensador = 3;  // Tempo en segundos que está ON o dispensador
int tEspera = 10;      // Tempo en segundos de espera antes de suministrar
unsigned long int tInicial = 0; // Importante: unsigned long int evita desbordamento
bool tempoCumplido = true;
bool pir = false;         // Estado do sensor de presenza

// -------- Declaración de E/S --------
void setup() {
  pinMode(PIR, INPUT);
  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, LOW);
  tInicial = millis();
  Serial.begin(9600);
}

// -------- Lóxica do dispensador --------
void loop() {
  // Lectura do sensor de presenza
  pir = !digitalRead(PIR);
  // Se o sensor está activo e pasou tempo suficiente
  if(pir && tempoCumplido) {
    //Serial.print("Estado sensor IR: "); Serial.println(pir);
    //Serial.print("Tempo cumplido: "); Serial.println(tempoCumplido);
    digitalWrite(RELAY, HIGH);  // ... activa dispensador
    //Serial.println("Relé ON");
    tInicial = millis();        // ... empeza temporización
  }
  //Se pasou o tempo que necesita o mecanismo dispensador...
  if(millis() - tInicial >= tDispensador * 1000) {
    digitalWrite(RELAY, LOW);  //  Apagamos dispensador
    //Serial.println("Relé OFF");
  }
  // Engadimos unha pequena espera antes de habilitar dispensador
  tempoCumplido = millis() - tInicial >= (tDispensador + tEspera) * 1000;
}

/*
 * Notas:
 * (a) O sensor IR de proximidade FC-51 dá saída LOW cando detecta presenza,
 *     por iso lemos o sensor co valor negado con '!';
 * (b) Algúns relés con dous LEDs (vermello/verde) poden indicar: vermello, relé
 *     alimentado e verde, relé OFF (LED verde apagado, relé ON, con consumo por
 *     estar activo).
 */
