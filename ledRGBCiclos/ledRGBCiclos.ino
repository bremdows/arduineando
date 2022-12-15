// LEDS
int led1 = 9;
int led2 = 10;
int led3 = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

}

int value = 20;

void loop() {
  // put your main code here, to run repeatedly:

  for(int i = 0; i <= 255; i++){
    
    if( i <= value){
      analogWrite(led1, i);
    }else{
      analogWrite(led1, value);
    }
    analogWrite(led2, i);
    analogWrite(led3, i);
    Serial.println(i);
    delay(100);
  }

}

