int pulsador = 7;
int motor = 3;
int interruptor = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // ENTRADAS y SALIDAS
  pinMode(pulsador, INPUT);
  pinMode(motor, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if ( digitalRead( pulsador) == 1){
    interruptor += 1;
    delay(500);
  }
  Serial.println( digitalRead(pulsador));

  if( interruptor == 1) {
    analogWrite(motor, 125);
  }
  if( interruptor == 2) {
    analogWrite(motor, 0);
    interruptor = 0;
  }
}
