#include <LiquidCrystal.h>    // importa libreria
// VARIABLES DE ENTRADA
int pinAnalogOut = A0;
int flujoMagneticoLeido = 0;
int flujoMagneticoMedido = 0;
int pinPulsadorCalibrador = 8;
int ledCalibracion = 9;

// INICIALIZANDO EL LCD
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);  // pines RS, E, D4, D5, D6, D7 de modulo 1602A

// VARIABLES DE MEDICIÓN
int valorCalibrado = 0;

int calibrarInstrumento( ){
  valorCalibrado = 0;
  for(int i = 0; i < 10; i++){
    lcd.setCursor(0, 0);
    lcd.print("Calibrando el");
    lcd.setCursor(0, 1);
    lcd.print("dispositivo ...");

    valorCalibrado += analogRead(pinAnalogOut);
    // PARPADEO DEL LED
    digitalWrite(ledCalibracion, HIGH);
    delay(250);
    digitalWrite(ledCalibracion, LOW);
    delay(250);
  }
  valorCalibrado /= 10;
  return valorCalibrado;
}

void setup() {
  // lcd.begin(16, 2);     // inicializa a display de 16 columnas y 2 lineas
  // Iniciando el Monitor Serial
  Serial.begin(9600);

  // DEFINIENDO ENTRADAS Y SALIDAS
  pinMode(pinPulsadorCalibrador, INPUT);
  pinMode(ledCalibracion, OUTPUT);
  
}

void loop() {
  /*  CALIBRACIÓN DEL INSTRUMENTO  */
  lcd.begin(16, 2);
  flujoMagneticoLeido = analogRead(pinAnalogOut);
  Serial.println(flujoMagneticoLeido);

  /* CALIBRANDO EL DISPOSITIVO */
  if( digitalRead(pinPulsadorCalibrador) == HIGH)  {
    calibrarInstrumento();
    delay(200);
  }


  /* FIN DE LA CALIBRACIÓN */

  lcd.setCursor(0, 0);      // ubica cursor en columna 0, linea 0
  lcd.print("Campo Magnetico ");  // escribe el texto en pantalla
  lcd.setCursor(0, 1);      // ubica cursor en columna 0, linea 1
  flujoMagneticoLeido = analogRead(pinAnalogOut);
  flujoMagneticoMedido = 3.75*(flujoMagneticoLeido - valorCalibrado);
  Serial.print(" G \n");
  lcd.print(flujoMagneticoMedido);   // escribe valor en segundos devuelto por funcion millis()
  lcd.print(" Gauss.");  // imprime a continuacion segundos
  delay(1000);

}


