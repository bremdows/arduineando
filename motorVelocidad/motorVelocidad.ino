int pulsador1 = 4;
int pulsador2 = 7;
int motor = 3;
int ledVerde = 8;
int ledAmbar = 9;
int ledRojo = 10;
int ledInterruptor = 11;
int retraso = 500;

int velocidades = 0;
int interruptor = 0;

void saludar(String texto ){
  Serial.println(texto);
}

void controlLeds( int on){
  for(int i = 8; i <= 10; i++){
    digitalWrite(i, LOW);
  }
  digitalWrite(on, HIGH);
}

void apagarLeds(){
  for(int i = 8; i <= 10; i++){
    digitalWrite(i, LOW);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // ENTRADAs 
  pinMode(pulsador1, INPUT);
  pinMode(pulsador2, INPUT);

  // SALIDAS
  // ACTIVANDO LOS LEDS
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmbar, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledInterruptor, OUTPUT);

  // ACTIVANDO EL MOTOR
  pinMode(motor, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if( digitalRead(pulsador1) == 1){
    interruptor += 1;
    delay(500);
  }
  
  // Serial.println( digitalRead(pulsador1) );

  if (interruptor == 1){

    if( digitalRead(pulsador2) == 1){
      velocidades += 1;
      delay(500);
    }
    Serial.println( digitalRead(pulsador2));  

    digitalWrite(ledInterruptor, HIGH);
    // CAMBIO EN EL FUNCIONAMIENTO
    switch(velocidades) {
      case 0 : 
        analogWrite(motor, 0);
        apagarLeds();
      break;
      case 1 :
        analogWrite(motor, 150);
        controlLeds(ledRojo);
      break;
      case 2 :
        analogWrite(motor, 190);
        controlLeds(ledAmbar);        
      break;
      case 3 :
        analogWrite(motor, 255);
        controlLeds(ledVerde);        
      break;
      default :
        velocidades = 1;
      break;
    }
  }
  if(interruptor == 2){
    analogWrite(motor, 0);

    digitalWrite(ledInterruptor, LOW);
    apagarLeds();
    interruptor = 0;
    velocidades = 0;
  }
}

