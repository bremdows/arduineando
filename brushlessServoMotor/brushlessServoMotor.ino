/* 
  FUNCIONALIDADES
  - Control de velocidad (potenciometro)
  - Encendido y apagado (pulsador)
  - Movimiento 0 - 180 y estatico (pulsador)
*/

#include <Servo.h> // librería para controlar servomotores

// Pulsadores
int pinPulsador= 7; 
int 
// Pin del ventilador
int ventilador = 9; 


// CONTROL DEL VENTILADOR 
int girar = 0;
int posicionVentilador = 0;


Servo servo; // declaración de un objeto servo
void setup() {
  servo.attach(ventilador); // conectamos el servo al pin 9
  pinMode(pinPulsador, INPUT); // configuramos el pin del botón como entrada
  pinMode(ventilador, OUTPUT);
}

void loop() {

  digitalWrite(ventilador, HIGH);

	if( digitalRead(pinPulsador)){
			girar += 1;
	}

	if( girar == 1){
		for (int i = 0; i <= 180; i += 1) { // giro desde 0 hasta 180 grados
      servo.write(i); // movemos el servo a la posición i
			posicionVentilador = i;
      delay(15); // esperamos 15 milisegundos

    }
    for (int i = 180; i >= 0; i -= 1) { // giro desde 180 hasta 0 grados
      servo.write(i);
			posicionVentilador = i;
			delay(15);
		}
	}

	if( girar == 2 ){
		servo.write(posicionVentilador);
	}

	if( girar == 3){
			girar = 1;
	}
}