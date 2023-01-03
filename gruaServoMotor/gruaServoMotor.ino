// AGREGANDO LA LIBRERÍA SERVOMOTOR
#include <Servo.h>

// AGREGANDO LA LIBRERIA PARA EL MOTOR PAP
#include <Stepper.h>

// VARIABLES DE CONTROL Y PINES 

int pinServoRotacion = 8;
int pinServoGrua = 9;

int pinEjeX = A0;
int pinEjeY = A1;

int ejeX = 90;
int ejeY = 90;

// CONTROL DEL ELEVADOR DE LA GRUA
int pinDireccionGrua = 7;
int pinEncendidoGrua = 6;
int interruptor = 0;
int direccionGrua = 0;

// INDICADORES VISUALES
int led = 10;

// VARIABLES DE LA LIBRERIA SERVO
Servo servoRotacion;
Servo servoGrua;

// VARIABLES PARA CONTROLAR EL MOTOR PASO A PASO
int pasosRevolucion = 2048;
int velocidadMotor = 10;
Stepper motorPAP(pasosRevolucion, 2, 3, 4, 5);


void setup() {

  // ENTRADAS Y SALIDAS
  pinMode(pinDireccionGrua, INPUT_PULLUP);
  pinMode(pinEncendidoGrua, INPUT);
  pinMode(led, OUTPUT);
  
  //  INDICANDO EL PIN DE CONEXIÓN DE LOS SERVOS
  servoRotacion.attach(pinServoRotacion);
  servoGrua.attach(pinServoGrua);

  // DEFINIENDO LA POSICIÓN DE LOS SERVOMOTORES
  servoRotacion.write(90);
  servoGrua.write(90);

  // DEFINIENDO LA VELOCIDAD DEL MOTOR PASO A PASO
  motorPAP.setSpeed(velocidadMotor);
}

void loop() {

  if( digitalRead(pinEncendidoGrua) == 1){
    interruptor++;
    delay(500);
  }
  
  if(interruptor == 1){
    // ENCENDER MOTOR PASO A PASO
    digitalWrite(led, HIGH);

    if ( digitalRead(pinDireccionGrua) == 0 ){
      direccionGrua++;
      delay(100);
    }
    switch(direccionGrua){
      case 0:
        pasosRevolucion = 0;
      case 1:
        pasosRevolucion = 2048;
      break;

      case 2:
        pasosRevolucion = -2048;
      break;
      
      case 3:
        direccionGrua = 0;
      break;
    }
    motorPAP.step(pasosRevolucion);
  }
  if(interruptor == 2){
    // APAGAR MOTOR PASO A PASO
    digitalWrite(led, LOW);
    motorPAP.step(0);
    interruptor = 0;
    pasosRevolucion = 0;
  }
  
  // CONTROL DEL EJE X - ROTACIÓN HORIZONTAL
  /* if( analogRead(pinEjeX) < 200 && ejeX < 180) {
    ejeX++;
    servoRotacion.write(ejeX);
  }

  if( analogRead(pinEjeX) > 700 && ejeX > 0) {
    ejeX--;
    servoRotacion.write(ejeX);
  }

  // CONTROL DEL EJE Y - ROTACIÓN VERTICAL
  if( analogRead(pinEjeY) < 200 && ejeY < 180) {
    ejeY++;
    servoGrua.write(ejeY);
  }

  if( analogRead(pinEjeY) > 700 && ejeY > 0) {
    ejeY--;
    servoGrua.write(ejeY);
  } */

  delay(15); 
}