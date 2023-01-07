/* LIBRERIA PARA LOS QUE LOS PINES DE ARDUINO SE COMPORTEN COMO CONEXIONES SERIALES*/
#include <SoftwareSerial.h>

// 10 - RX
// 11 - TX
SoftwareSerial miBT(10, 11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(" ARDUINO & MODULO BLUETOOTH LISTO ");  

  // VELOCIDAD DE COMUNICACIÓN DEL MÓDULO BLUEETOOTH
  miBT.begin(38400);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  // available() retorna verdadero cuando existe información disponible desde arduino
  if( miBT.available()){ // LEE BT Y ENVIA A ARDUINO
    Serial.write( miBT.read() );
  }

  if( Serial.available()){ // LEE ARDUINO Y ENVIA A BT 
    miBT.write( Serial.read() );
  }
  

}
