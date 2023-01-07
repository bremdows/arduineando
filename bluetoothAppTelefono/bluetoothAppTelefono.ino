/* LIBRERIA PARA LOS QUE LOS PINES DE ARDUINO SE COMPORTEN COMO CONEXIONES SERIALES*/
#include <SoftwareSerial.h>

// 10 - RX
// 11 - TX
SoftwareSerial miBT(10, 11);

char status = 0;
int ledUno = 5;
int ledDos = 6;


int brillo = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(" ARDUINO & MODULO BLUETOOTH LISTO ");   

  // VELOCIDAD DE COMUNICACIÓN DEL MÓDULO BLUEETOOTH
  miBT.begin(38400);

  // INICIAR LOS LEDS
  pinMode(ledUno, OUTPUT);
  pinMode(ledDos, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  // available() retorna verdadero cuando existe información disponible desde arduino

  if( miBT.available()){ // LEE BT Y ENVIA A ARDUINO
    status = miBT.read();
    
    switch(status){
      case '1': 
        digitalWrite(ledUno, !digitalRead(ledUno));
        
      break;

      case '2': 
        analogWrite(ledDos, brillo);
        brillo += 50;

        if(brillo > 250){
          brillo = 0;
        }
      break;
    }
  } 
}