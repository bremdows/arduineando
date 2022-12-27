/* 
  FUNCIONALIDADES
  - Control de velocidad (potenciometro)
  - Encendido y apagado (pulsador)
  - Movimiento 0 - 180 y estatico (pulsador)
*/

#include <Servo.h> // librería para controlar servomotores

// PULSADORES
int pulsadorInterruptor = 2; 
int pulsadorGiro = 3;
int potenVelocidadVentilador = A0;

// PIN PARA EL VENTILADOR
int pinServoVentilador = 5;  
int ventilador = 9;


// VARIABLES DE CONTROL
int interruptor = 0;
int giroVentilador = 0;
int velocidadVentilador = 0;

int posicionVentilador = 0;
int retrasoServo = 15;

// VARIABLE - OBJETO SERVO PARA EL VENTILADOR
Servo servoVentilador; 
void setup() {
	Serial.begin(9600);
	// ENTRADAS
	pinMode(pulsadorInterruptor, INPUT); 
	pinMode(pulsadorGiro, INPUT);

	// SALIDAS
	pinMode(pinServoVentilador, OUTPUT); // SERVO
	pinMode(ventilador, OUTPUT); // VENTILADOR

	// CONFIGURANDO EL PUERTO ARDUINO AL VENTILADOR
	servoVentilador.attach(pinServoVentilador);
	// INICIANDO EL VENTILADOR EN LA POSICIÓN PREDETERMINADA
	servoVentilador.write( posicionVentilador);

	analogWrite(ventilador, 0);

}

void loop() {

	// CONFIGURACIÓN DE LAS VARIABLES DE CONTROL

	if( digitalRead(pulsadorInterruptor) == 1){
		interruptor += 1;
		delay(500);
	}

	if( digitalRead(pulsadorGiro) == 1){
		giroVentilador += 1;
		delay(500);
	}

	/* 
		CODIGO DE CONTROL PARA EL FUNCIONAMIENTO
		- Encendido - Apagado
		- Velocidad
	*/	
	
	// VENTILADOR ENCENDIDO
	if (interruptor == 1){
		// CONTROL DE VELOCIDAD	
		velocidadVentilador = map( analogRead(potenVelocidadVentilador), 0, 1023, 0, 255);
		analogWrite(ventilador, velocidadVentilador);
		Serial.println("ON");
		Serial.println(velocidadVentilador);

		switch(giroVentilador){
			case 0:
				// GIRO DE 0º - 180º
				for (posicionVentilador = 0; posicionVentilador <= 180; posicionVentilador += 1) {
					servoVentilador.write(posicionVentilador); // 
					delay(retrasoServo);

				}
				// GIRO DE 180º - 0º
				for (posicionVentilador = 180; posicionVentilador >= 0; posicionVentilador -= 1) { // giro desde 180 hasta 0 grados
					servoVentilador.write(posicionVentilador);
					delay(retrasoServo);
				}
			break;
			case 1:
				// MANTENER LA POSICIÓN
				servoVentilador.write(posicionVentilador);
			break;
			default :
				giroVentilador = 0;
			break;
		}

	}
	// VENTILADOR APAGADO
	if( interruptor == 2){
		Serial.println("OFF");
		analogWrite(ventilador, 0);
		interruptor = 0;
	}
}