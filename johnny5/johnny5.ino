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
          digitalWrite(pinMotor1A, HIGH);
          digitalWrite(pinMotor1B, LOW);

          digitalWrite(pinMotor2A, LOW);
          digitalWrite(pinMotor2B, HIGH);          
        break;
        
        case 'S' :
          // * RETROCEDER
          digitalWrite(pinMotor1A, LOW);
          digitalWrite(pinMotor1B, HIGH);

          digitalWrite(pinMotor2A, HIGH);
          digitalWrite(pinMotor2B, LOW);
        break;

        case 'A' :
          // * IZQUIERDA
          digitalWrite(pinMotor1A, LOW);
          digitalWrite(pinMotor1B, LOW);

          digitalWrite(pinMotor2A, LOW);
          digitalWrite(pinMotor2B, HIGH);
        break;

        case 'D' :
          // * DERECHA

          digitalWrite(pinMotor1A, HIGH);
          digitalWrite(pinMotor1B, LOW);

          digitalWrite(pinMotor2A, LOW);
          digitalWrite(pinMotor2B, LOW);
        break;

        case 'Q' :
          // * MOVER BRAZO IZQUIERDO (ARRIBA - ABAJO)
          if(posicionBrazoI == 180){
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
          }
          // posicionBrazoI += cambioMovimiento;
          servoBrazoIzquierdo.write(posicionBrazoI);
        break;

        case 'E' :
          // * MOVER BRAZO DERECHO (ARRIBA - ABAJO)
          if(posicionBrazoD == 180){
            estadoBD = 1;
          }
          if(posicionBrazoD == 0){
            estadoBD = 0;
          }
          if(estadoBD == 0){
            posicionBrazoD += cambioMovimiento;
          }
          if(estadoBD == 1){
            posicionBrazoD -= cambioMovimiento;
          }
          // posicionBrazoI -= cambioMovimiento;
          servoBrazoDerecho.write(posicionBrazoD);
        break;

        case 'R':
          // * CABEZA A LA IZQUIERDA
          if( validarMovServo(posicionCabeza) ){
            posicionCabeza -= cambioMovimiento;
            servoCabeza.write(posicionCabeza);
          }else{
            posicionCabeza = reiniciarValor(posicionCabeza);
          }
        break;

        case 'T':
          // * CABEZA A LA DERECHA
          if( validarMovServo(posicionCabeza) ){
            posicionCabeza += cambioMovimiento;
            servoCabeza.write(posicionCabeza);
          }else{
            posicionCabeza = reiniciarValor(posicionCabeza);
          }
        break;
        
        case 'Z':
          // * DORSO A LA IZQUIERDA
          if( validarMovServo(posicionTorzo) ){
            posicionTorzo -= cambioMovimiento;
            servoTorzo.write(posicionTorzo);
          }else{
            posicionTorzo = reiniciarValor(posicionTorzo);
          }
        break;
        
        case 'X':
          // * DORSO A LA DERECHA
          if( validarMovServo(posicionTorzo) ){
            posicionTorzo += cambioMovimiento;
            servoTorzo.write(posicionTorzo);
          }else{
            posicionTorzo = reiniciarValor(posicionTorzo);
          }
        break;
      }    
      // * POR DEFECTO APAGAR LOS MOTORES DE MOV. (REDUCTORES) SI NO SE ESTA PRESIONANDO UNA TECLA
      delay(110);
      apagarMotoresReductores();
  } 

}

boolean validarMovServo(int posicionServo){
  if( posicionServo >= 0 && posicionServo <= 180)
    return true;
  else                
    return false;
}

int reiniciarValor( int posicionServo ){
  if( posicionServo > 180){
    return 180;
  }else if( posicionServo < 0){
    return 0;
  }
}

void apagarMotoresReductores(){
  digitalWrite(pinMotor1A, LOW);
  digitalWrite(pinMotor1B, LOW);

  digitalWrite(pinMotor2A, LOW);
  digitalWrite(pinMotor2B, LOW);
}









