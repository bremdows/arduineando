// LIBRERIAS
#include <LiquidCrystal.h>

// VARIABLES DE ENTRADA, SALIDA Y CONTROL
int pulsador = 3;
int motor = 4;

void setup() {
  // PIN PULSADOR
  pinMode(pulsador, INPUT);

  // PIN MOTOR
  pinMode(motor, OUTPUT);
}

void loop() {
  // Mientras presione el botón que el motor empieze a funcionar
  while (pulsador == 1){       
    analogWrite(motor, 255);
  }
  // Luego el motor tiene que parar lentamente durante los 5seg próximos
  for(int i = 255; i >= 0; i--){
    analogWrite(motor, i);
    delay(20);
  }
  

}