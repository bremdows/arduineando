int speedPin = 3;
int dir1 = 8;
int dir2 = 13;

int speedMotor = 150;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // ENTRADAS Y SALIDAS
  pinMode(speedPin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  // digitalWrite(dir1, 1);
  // digitalWrite(dir2, 2);
  // analogWrite(speedPin, speedMotor);

  for (int  i = 1; i <= 2; i++){
    switch(i){
      case 1: 
        digitalWrite(dir1, 1);
        digitalWrite(dir2, 0);
      break;
      case 2:
        digitalWrite(dir1, 0);
        digitalWrite(dir2, 1);
      break;
    }
    analogWrite(speedPin, speedMotor);

    delay(5000);
  }
}