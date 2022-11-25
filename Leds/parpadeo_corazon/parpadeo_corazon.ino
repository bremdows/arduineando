void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  for(int i = 2; i <= 7; i++){
    pinMode(i, OUTPUT);
  }
}
int tiempo = 5;
void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 2; i <= 7; i++){

    for(int j = 0; j <= 1; j++){
      digitalWrite(i, HIGH);
      delay(100);
      digitalWrite(i, LOW);
      delay(100);
    }
    delay(1000);
    
  }
  
}
