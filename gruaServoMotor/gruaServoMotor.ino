// AGREGANDO LA LIBRERÍA SERVOMOTOR
#include <Servo.h>
// VARIABLES DE CONTROL Y PINES 

int pinServoRotacion = 8;
int pinServoGrua = 9;

int pinEjeX = A0;
int pinEjeY = A1;

int ejeX = 90;
int ejeY = 90;

// CONTROL DEL ELEVADOR DE LA GRUA
int pinGruaBoton = 7;
int interruptor = 0;

// VARIABLES DE LA LIBRERIA SERVO

Servo servoRotacion;
Servo servoGrua;


void setup() {
  // INICIANDO EL MONITOR SERIAL
  Serial.begin(9600);

  // ENTRADAS Y SALIDAS
  pinMode(pinGruaBoton, INPUT_PULLUP);
  
  //  INDICANDO EL PIN DE CONEXIÓN DE LOS SERVOS
  servoRotacion.attach(pinServoRotacion);
  servoGrua.attach(pinServoGrua);

  // DEFINIENDO LA POSICIÓN DE LOS SERVOMOTORES
  servoRotacion.write(90);
  servoGrua.write(90);
}

void loop() {
  
  Serial.println( digitalRead(pinGruaBoton));

  if( digitalRead(pinGruaBoton) == 0){
    interruptor++;
    delay(100);
  }
  if(interruptor == 1){
    // ENCENDER MOTOR PASO A PASO
    Serial.println("Encendido");
  }
  if(interruptor == 2){
    // APAGAR MOTOR PASO A PASO
    Serial.println("APAGADO");
    interruptor = 0;
  }
 /*  // CONTROL DEL EJE X - ROTACIÓN HORIZONTAL
  if( analogRead(pinEjeX) < 200 && ejeX < 180) {
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
  }

  delay(15); */
}

