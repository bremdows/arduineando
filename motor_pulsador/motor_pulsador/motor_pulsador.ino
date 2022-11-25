int pulsador = 7;
int motor = 3;
int interruptor = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(pulsador, INPUT);
  pinMode(motor, OUTPUT);
  pinMode(13, OUTPUT);
  
  digitalWrite(motor, LOW);
  
}

void loop()
{
  digitalWrite(13, LOW);
  Serial.println( digitalRead(pulsador) );

  if( digitalRead(pulsador) == 1 ){
    interruptor += 1;
  }
    
  if(interruptor == 1){
    digitalWrite(motor, HIGH);
  }
  if(interruptor == 2){
    digitalWrite(motor, LOW);
    interruptor = 0;
  }
}



