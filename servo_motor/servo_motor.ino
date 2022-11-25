#include <Servo.h> // INCLUIR LIBRERÍA PARA EL SERVOMOTOR


Servo servo1;

int PINSERVO = 6;
int PULSONMIN = 500;
int PULSOMAX = 2500;
int i;


void setup() {
  // .attach() DEFINE EL RANGO EN EL CUAL SE MOVERA EL SERVOMOTOR
  servo1.attach(PINSERVO, PULSOMIN, PULSOMAX);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  servo1.write(90); // que se mueva a la derecha 90 grados
  delay(1000);
  
  servo1.write(-90) // se mueve a la derecha 90 grados
  for(i = 0; i < 20; i++){
    // para para hacer, auns
  }

}
