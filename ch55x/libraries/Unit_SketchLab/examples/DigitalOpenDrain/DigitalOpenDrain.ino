#include <Serial.h>

void setup() {
  // No need to init USBSerial

  // Configurar el pin 2 como entrada y habilitar la resistencia pull-up interna
  pinMode(11, INPUT_PULLUP);
  pinMode(33, OUTPUT);
}

void loop() {
  // Leer el valor del botón en una variable
  int sensorVal = digitalRead(11);
  // Imprimir el valor del botón en el monitor serial
  USBSerial_println(sensorVal);

  // Dado que el pull-up significa que la lógica del botón está invertida,
  // encender el LED cuando el botón está presionado y apagarlo cuando está abierto:
  if (sensorVal == HIGH) {
    digitalWrite(33, LOW);
  } else {
    digitalWrite(33, HIGH);
  }

  delay(10);
}