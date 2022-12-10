nt speedPin1 = 11;
int dirPin11 = 12; 
int dirPin12 = 8;
int speedPin2 = 6;
int dirPin21 = 4;
int dirPin22 = 2;
int speedMotor = 100;
int delayTime = 300;
char direccion;
int button = 0;
int button1 = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(speedPin1, OUTPUT);
  pinMode(dirPin11, OUTPUT);
  pinMode(dirPin12, OUTPUT);
  pinMode(speedPin2, OUTPUT);
  pinMode(dirPin21, OUTPUT);
  pinMode(dirPin22, OUTPUT);
  
}

void loop()
{
  direccion = Serial.read();
  
  if(direccion == '+'){
    button = 1;
  }
  if(direccion == '-'){
    button = 2;
  }
  if(direccion == '0'){
    button = 3;
  }
  if(direccion == '1'){
    button1 = 1;
  }
  if(direccion == '2'){
    button1 = 2;
  }
  if(direccion == '3'){
    button1 = 3;
  }
  
  if( (button == 1) && (button1 == 1)){
    speedMotor = 150;
  }
  if( (button == 1) && (button1 == 2)){
    speedMotor = 200;
  }
  if( (button == 1) && (button1 == 3)){
    speedMotor = 255;
  }

  if( (button == 2) && (button1 == 1)){
    speedMotor = 150;
  }
  if( (button == 2) && (button1 == 2)){
    speedMotor = 200;
  }
  if((button == 2) && (button1 == 3)){
    speedMotor = 255;
  }

  if(button == 1){
    //GIRO HORARIO
    digitalWrite(dirPin11, LOW);
    digitalWrite(dirPin12, HIGH);
    analogWrite(speedPin1, speedMotor);
    delay(delayTime);
    digitalWrite(dirPin12, LOW);

    digitalWrite(dirPin11, HIGH);
    digitalWrite(dirPin12, LOW);
    analogWrite(speedPin1, speedMotor);
    delay(delayTime);
    digitalWrite(dirPin11, LOW);

    digitalWrite(dirPin21, LOW);
    digitalWrite(dirPin22, HIGH);
    analogWrite(speedPin2, speedMotor);
    delay(delayTime);
    digitalWrite(dirPin22, LOW);

    digitalWrite(dirPin21, HIGH);
    digitalWrite(dirPin22, LOW);
    analogWrite(speedPin2, speedMotor);
    delay(delayTime);
    digitalWrite(dirPin21, LOW);
  }

  if(button == 2){
    //GIRO ANTIHORARIO
    digitalWrite(dirPin21, HIGH);
    digitalWrite(dirPin22, LOW);
    analogWrite(speedPin2, speedMotor);
    delay(delayTime);
    digitalWrite(dirPin21, LOW);

    digitalWrite(dirPin21, LOW);
    digitalWrite(dirPin22, HIGH);
    analogWrite(speedPin2, speedMotor);
    delay(delayTime);
    digitalWrite(dirPin22, LOW);
    
    digitalWrite(dirPin11, HIGH);
    digitalWrite(dirPin12, LOW);
    analogWrite(speedPin1, speedMotor);
    delay(delayTime);
    digitalWrite(dirPin11, LOW);

    digitalWrite(dirPin11, LOW);
    digitalWrite(dirPin12, HIGH);
    analogWrite(speedPin1, speedMotor);
    delay(delayTime);
    digitalWrite(dirPin12, LOW);
  }

  if(button == 3){
    digitalWrite(dirPin11, LOW);
    digitalWrite(dirPin12, LOW);
    digitalWrite(dirPin21, LOW);
    digitalWrite(dirPin22, LOW);
  }

}