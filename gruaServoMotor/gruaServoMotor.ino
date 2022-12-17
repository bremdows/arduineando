// AGREGANDO LA LIBRERÍA SERVOMOTOR
#include <Servo.h>
// VARIABLES DE CONTROL Y PINES 

int pinServoRotacion = 7;
int pinServoGrua = 8;
int pinEjeX = A0;
int pinEjeY = A1;

int ejeX = 90;
int ejeY = 90;

// VARIABLES DE LA LIBRERIA SERVO

Servo servoRotacion;
Servo servoGrua;


void setup() {
  //  INDICANDO EL PIN DE CONEXIÓN DE LOS SERVOS
  servoRotacion.attach(pinServoRotacion);
  servoGrua.attach(pinServoGrua);

  // DEFINIENDO LA POSICIÓN DE LOS SERVOMOTORES
  servoRotacion.write(90);
  servoGrua.write(90);

}

void loop() {
  
  // CONTROL DEL EJE X - ROTACIÓN HORIZONTAL
  if( analogRead(pinEjeX) < 200 && ejeX < 180) ){
    ejeX++;
    servoRotacion.write(ejeX);
  }

  if( analogRead(pinEjeX) > 700 && ejeX > 0) ){
    ejeX--;
    servoRotacion.write(ejeX);
  }

  // CONTROL DEL EJE Y - ROTACIÓN VERTICAL
  if( analogRead(pinEjeY) < 200 && ejeY < 180) ){
    ejeY++;
    servoGrua.write(ejeY);
  }

  if( analogRead(pinEjeY) > 700 && ejeY > 0) ){
    ejeY--;
    servoGrua.write(ejeY);
  }

  delay(15);
}

