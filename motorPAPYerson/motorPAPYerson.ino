//PARA EL CONTROL DE BOBINAS
int PinLeft1 = 8;
int PinLeft2 = 9; 
int PinRight1 = 10;
int PinRight2 = 11;
//PARA EL ENCENDIDO Y APAGADO DEL MOTOR
int SwetchLeft = 5;
int SwetchRigth = 6;
//PARAMETROS INICIALES DEL MOTOR
int speedMotor = 255;
int delayTime = 80;
char direccion;
int button = 0;
int button1 = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(PinLeft1, OUTPUT);
  pinMode(PinLeft2, OUTPUT);
  pinMode(PinRight1, OUTPUT);
  pinMode(PinRight2, OUTPUT);
  pinMode(SwetchLeft, OUTPUT);
  pinMode(SwetchRigth, OUTPUT);
  analogWrite(SwetchLeft, speedMotor);
  analogWrite(SwetchRigth, speedMotor);
  
}

void loop()
{
  direccion = Serial.read();
  if(direccion == '+'){
    button = 1;
     analogWrite(SwetchLeft, speedMotor);
    analogWrite(SwetchRigth, speedMotor);
  }
  if(direccion == '-'){
    button = 2;
     analogWrite(SwetchLeft, speedMotor);
    analogWrite(SwetchRigth, speedMotor);
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
  if((button == 1) && (button1 == 1)){
    delayTime = 40;
  }
  if((button == 1) && (button1 == 2)){
    delayTime = 20;
  }
  if((button == 1) && (button1 == 3)){
    delayTime = 4;
  }

  if((button == 2) && (button1 == 1)){
    delayTime = 40;
  }
  if((button == 2) && (button1 == 2)){
    delayTime = 20;
  }
  if((button == 2) && (button1 == 3)){
    delayTime = 4;
  }

  if(button == 1){
    //GIRO HORARIO

    digitalWrite(PinLeft1, HIGH);
    digitalWrite(PinLeft2, LOW);
    digitalWrite(PinRight1, LOW);
    digitalWrite(PinRight2, LOW);
    delay(delayTime);
    
    digitalWrite(PinLeft1, LOW);
    digitalWrite(PinLeft2, HIGH);
    digitalWrite(PinRight1, LOW);
    digitalWrite(PinRight2, LOW);
    delay(delayTime);
   
    digitalWrite(PinLeft1, LOW);
    digitalWrite(PinLeft2, LOW);
    digitalWrite(PinRight1, HIGH);
    digitalWrite(PinRight2, LOW);
    delay(delayTime);

    digitalWrite(PinLeft1, LOW);
    digitalWrite(PinLeft2, LOW);
    digitalWrite(PinRight1, LOW);
    digitalWrite(PinRight2, HIGH);
    delay(delayTime);

    
  }
  

  if(button == 2){
    //GIRO ANTIHORARIO
    digitalWrite(PinLeft1, HIGH);
    digitalWrite(PinLeft2, LOW);
    digitalWrite(PinRight1, LOW);
    digitalWrite(PinRight2, LOW);
    delay(delayTime);
    
    digitalWrite(PinLeft1, LOW);
    digitalWrite(PinLeft2, LOW);
    digitalWrite(PinRight1, LOW);
    digitalWrite(PinRight2, HIGH);
    delay(delayTime);
   
    digitalWrite(PinLeft1, LOW);
    digitalWrite(PinLeft2, LOW);
    digitalWrite(PinRight1, HIGH);
    digitalWrite(PinRight2, LOW);
    delay(delayTime);

    digitalWrite(PinLeft1, LOW);
    digitalWrite(PinLeft2, HIGH);
    digitalWrite(PinRight1, LOW);
    digitalWrite(PinRight2, LOW);
    delay(delayTime);
  }

  if(button == 3){
    analogWrite(SwetchLeft, 0);
    analogWrite(SwetchRigth, 0);
  }
}