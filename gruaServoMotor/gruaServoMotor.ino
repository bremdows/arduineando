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
int pinDireccionGrua = 7;
int pinEncendidoGrua = 6;
int interruptor = 0;
int direccionGrua = 0;

// INDICADORES VISUALES
int led = 10;

// VARIABLES DE LA LIBRERIA SERVO
Servo servoRotacion;
Servo servoGrua;


void setup() {
  // INICIANDO EL MONITOR SERIAL
  // Serial.begin(9600);

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
}

void loop() {

  if( digitalRead(pinEncendidoGrua) == 1){
    interruptor++;
    delay(500);
  }
  if(interruptor == 1){
    // ENCENDER MOTOR PASO A PASO
    digitalWrite(led, HIGH);
    // Serial.println("ENCENDIDO");

    if ( digitalRead(pinDireccionGrua) == 0 ){
      direccionGrua++;
      delay(100);
    }
    switch(direccionGrua){
      case 1:
        // Serial.println("GIRO HORARIO");
      break;

      case 2:
        // Serial.println("GIRO ANTI-HORARIO");
      break;
      
      case 3:
        direccionGrua = 1;
      break;
    }
  }
  if(interruptor == 2){
    // APAGAR MOTOR PASO A PASO
    digitalWrite(led, LOW);
    // Serial.println("APAGADO");
    interruptor = 0;
  }
  
  // CONTROL DEL EJE X - ROTACIÓN HORIZONTAL
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

  delay(15); 
}