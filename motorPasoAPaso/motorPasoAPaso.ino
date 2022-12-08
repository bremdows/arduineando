// CONTROL DE UN MOTOR PASO A PASO 
#include <Stepper.h>
// definiendo cuantos pasos debe de dar el motor para dar una vuelta completa
int stepsPerRev = 2048;
// Velocidad del Motor
int motorSpeed = 10;
// Crear el stteper y especificar los pines de conexión del Stepper
Stepper myStepper(stepsPerRev, 8, 10, 9, 11);
// Definir un delay
int dl = 1500;

void setup() {
  // Velocidad del motor paso a paso
  myStepper.setSpeed(motorSpeed);
}


void loop() {
  // Definiendo el paso (Para que realice un rev completa = 2048)
  /* 
    Si el step fuese 1, sería 1/2048 parte para que de una vuelta
  */
  myStepper.step(stepsPerRev);
  delay(dl);
  myStepper.step(-stepsPerRev);
  delay(dl);
}
