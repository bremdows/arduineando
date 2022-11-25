#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int lectura = 0;
int led = 8;


void setup() {
  // Iniciando la comunicación serial
  Serial.begin(9600);
  // Iniciando los puertos para el LCD
  lcd.begin(16, 2);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  lectura = analogRead(0);

  // Imprimiendo el valor en el LCD
  lcd.setCursor(0, 0);
  lcd.print("Value FR:");
  lcd.setCursor(0, 1);
  lcd.print(lectura);
  if( lectura > 350){
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
  }
  delay(500);
  lcd.clear();
  

  //prend
  
  
}
