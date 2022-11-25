int pulsador = 4;
int motor = 6;
int interruptor = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pulsador, INPUT);
  pinMode(motor, OUTPUT);

  // Apagando el motor por defecto
  digitalWrite(motor, 0);

}

void loop() {
  // put your main code here, to run repeatedly:
  if( digitalRead(pulsador) == 1){
    interruptor += 1;
    delay(200);
  }

  if ( interruptor == 1 ){
    digitalWrite(motor, HIGH);
  }
  if( interruptor == 2 ){
    digitalWrite(motor, LOW);xz
    interruptor = 0;
  }
  Serial.println( digitalRead(pulsador));
  delay(500);

  // for(int i = 0; i <= 255; i++){
    
  //   analogWrite(motor, i);
  //   // if( i < 150){
  //   //   digitalWrite(leds[0], HIGH);
  //   // }else if( i < 230){
  //   //   digitalWrite(leds[1], HIGH);
  //   //   digitalWrite(leds[0], LOW);
  //   // }else{
  //   //   digitalWrite(leds[2], HIGH);
  //   //   digitalWrite(leds[1], LOW);
  //   // }
    
  //   Serial.println(i); 
  //   delay(500);
  // }
  // for(int i = 255; i >= 0; i--){
    
  //   analogWrite(motor, i);
  //   // if( i < 150){
  //   //   digitalWrite(leds[0], HIGH);
  //   // }else if( i < 230){
  //   //   digitalWrite(leds[1], HIGH);
  //   //   digitalWrite(leds[0], LOW);
  //   // }else{
  //   //   digitalWrite(leds[2], HIGH);
  //   //   digitalWrite(leds[1], LOW);
  //   // }
    
  //   Serial.println(i); 
  //   delay(500);
  // }
  //   // apagarLeds();
  //   // Fin del primer for
  //   /* for(int i = 255; i >= 0; i--){
  //     analogWrite(motor, i);
  //     if( i < 150){
  //       digitalWrite(leds[0], HIGH);
  //     }else if( i < 230){
  //       digitalWrite(leds[1], HIGH);
  //       digitalWrite(leds[0], LOW);
  //     }else{
  //       digitalWrite(leds[2], HIGH);
  //       digitalWrite(leds[1], LOW);
  //     }
  //     delay(100);

  //   } */
  //   // Fin del 2do for
}

// void apagarLeds(){
//   for( int i = 0; i < 3; i++){
//     digitalWrite(leds[i], LOW);
//   }
// }
