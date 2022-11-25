int pulsador = 3;
int motor = 6;
int interruptor = 0;
int led = 8;

void setup() {
  // Función que se ejecuta al iniciar Arduino
  Serial.begin(9600);

  pinMode(pulsador, INPUT);
  pinMode(motor, OUTPUT);
  pinMode(led, OUTPUT);
  
  digitalWrite(motor, LOW);

}
// Función que se ejecuta continuamente (mediante un bucle) mientras arduino esta funcionando

void loop(){

  /* for(int i = 0; i <= 255; i++){
    analogWrite(motor, i);
    Serial.println(i);
    delay(500);
  }

  for(int i = 255; i >= 0; i--){
    analogWrite(motor, i);
    Serial.println(i);
    delay(500);
  } */
  
  if( digitalRead(pulsador) == HIGH) 
    interruptor += 1;
    delay(500);
  }

  if( interruptor == 1){
    digitalWrite(motor, HIGH);
    digitalWrite(led, HIGH);
  }
  if(interruptor >= 2){
    digitalWrite(motor, LOW);
    digitalWrite(led, LOW);
    interruptor = 0;
  }
}
