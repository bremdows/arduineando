// AGREGANDO LA LIBRERIA DEL SERVO
#include <Servo.h>
int servoPin = 3;

// Define el angulo de movimiento para el Servo Motor
int servoAngle = 90;

// Utilizando la libreria
Servo myServo;

//
void setup() {
  Serial.begin(9600);
  // Función para indicarle a la libreria el pin de trabajo del Servo
  myServo.attach(servoPin);

}

void loop() {
  
  /* 
    Posicionar el ServoMotor a 90º
    write() Se utiliza como una función a modo de entrada analogica
  */

  // myServo.write(servoAngle);

  // Controlando el servo mediante el monitor Serial
  Serial.println("¿Entre 10 y 170 en que angulo desea mover el Servo Motor");
  while( Serial.available() == 0){}
  servoAngle = Serial.parseInt();
  myServo.write(servoAngle);

}