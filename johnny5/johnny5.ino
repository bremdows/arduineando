/*
  * FUNCIONALIDADES 

  TODO: MOVIMIENTO DE LOS BRAZOS SERVO MOTORES
  TODO: CONTROL DE LOS MOTORES DC
  TODO: MOVIMIENTO DEL TORZO
  TODO: MOV. DE LA CABEZA
*/

/*  
  * AGREGANDO LA LIBRERIA SERVO
*/
#include <Servo.h>


/*
  * VARIABLES DE CONTROL
*/

// * ESTADO
char status = 0;
int estadoBI = 0;
int estadoBD = 0;

// * CAMBIO MOVIMIENTO 
int cambioMovimiento = 20;

// * POSICIONES INICIALES
int posicionBrazoI = 0;
int posicionBrazoD = 120;
int posicionTorzo = 90;
int posicionCabeza = 90;
/*
  * VARIABLES DEL MOTOR
*/
int pinMotor1A = 2;
int pinMotor1B = 3;
int pinMotor2A = 4;
int pinMotor2B = 5;

/* 
  * VARIABLES PARA LOS SERVOS
*/
int pinServoTorzo = 6;
int pinServoCabeza = 7;
int pinServoBrazoDerecho = 8;
int pinServoBrazoIzquierdo = 9;

Servo servoTorzo;
Servo servoCabeza;
Servo servoBrazoDerecho;
Servo servoBrazoIzquierdo;

/*
  * INICIALIZANDO VARIABLES DE CONTROL
*/

void setup() {

  // * INICIANDO EL MONITOR SERIAL COMO RECEPTOR DEL MÓDULO BLUETOOTH
  Serial.begin(38400);
  
  // * ESTABLECIENDO PIN DE CONTROL PARA EL SERVOMOTOR
  servoTorzo.attach(pinServoTorzo);
  servoCabeza.attach(pinServoCabeza);
  servoBrazoDerecho.attach(pinServoBrazoDerecho);
  servoBrazoIzquierdo.attach(pinServoBrazoIzquierdo);

  // * DEFINIENDO UNA POSICIÓN INICIAL A LOS SERVOMOTORES
  servoTorzo.write(posicionTorzo);
  servoCabeza.write(posicionCabeza);
  servoBrazoIzquierdo.write(posicionBrazoI);
  servoBrazoDerecho.write(posicionBrazoD);

}

void loop() {
  
  /*
    * LEYENDO VALORES DESDE EL MONITOR SERIAL MEDIANTE EL MÓDULO BLUETOOTH
  */

  if( Serial.available()){
    status = Serial.read();
    switch(status){
        case 'W' :
          // * AVANZAR
        break;
        
        case 'S' :
          // * RETROCEDER
        break;

        case 'A' :
          // * IZQUIERDA
        break;

        case 'D' :
          // * DERECHA
        break;

        case 'Q' :
          // * MOVER BRAZO IZQUIERDO (ARRIBA - ABAJO)
          /* if(posicionBrazoI == 180){
            estadoBI = 1;
          }
          if(posicionBrazoI == 0){
            estadoBI = 0;
          }
          if(estadoBI == 0){
            posicionBrazoI += cambioMovimiento;
          }
          if(estadoBI == 1){
            posicionBrazoI -= cambioMovimiento;
          } */
          posicionBrazoI += cambioMovimiento;
          servoBrazoIzquierdo.write(posicionBrazoI);
        break;

        case 'E' :
          // * MOVER BRAZO DERECHO (ARRIBA - ABAJO)
          /* if(posicionBrazoD == 180){
            estadoBD = 1;
          }
          if(posicionBrazoI == 0){
            estadoBD = 0;
          }
          if(estadoBD == 0){
            posicionBrazoD += cambioMovimiento;
          }
          if(estadoBI == 1){
            posicionBrazoD -= cambioMovimiento;
          } */
          posicionBrazoI -= cambioMovimiento;
          servoBrazoIzquierdo.write(posicionBrazoI);
        break;

        case 'R':
          // * CABEZA A LA IZQUIERDA
        break;

        case 'T':
          // * CABEZA A LA DERECHA
        
        break;
        
        case 'Z':
          // * DORSO A LA IZQUIERDA
        break;
        
        case 'X':
          // * DORSO A LA DERECHA
        break;
      }    
  } 

}
