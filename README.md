# dispensador-liquidos
Script para xestionar a dispensación de líquidos empregando un sensor de presenza

Para xestionar a dispensación de líquidos usaremos un relé que activa/desactiva a alimentación dun motor que por súa vez pon en marcha o mecanismo. A activación do relé terá lugar cando se detecte a presenza dun obxecto suficientemente cercano. Os detectores empregados poden ser varios, tanto con saída dixital como analóxica. Entre os detectores dixitais, fixemos probas co sensor de presenza PIR HC-SR501 (pode ser calquera outro da familia) e cun sensor de distancia IR FC-51. O sensor analóxico que se vai empregar é o Allnet 4duino B36.

A modo de proba, está dispoñible un único script que lé tanto entrada analóxica como dixital. Aparte deste, facilítanse dous scripts para uso definitivo: (a) para entrada analóxica e (b) para entrada dixital.

Máis información dos sensores probados:
HC-SR501: https://cdn-learn.adafruit.com/downloads/pdf/pir-passive-infrared-proximity-motion-sensor.pdf
FC-51: https://www.playembedded.org/blog/detecting-obstacle-with-ir-sensor-and-arduino/
B36: https://shop.allnet.de/media/pdf/3c/d6/d2/142989-Datenblatt_ES.pdf


