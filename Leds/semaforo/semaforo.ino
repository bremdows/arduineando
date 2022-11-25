int tiempo = 500;
int j = 0;
void setup() {
  // put your setup code here, to run once:
  for(int i = 2; i <= 7; i++){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(2, HIGH);
  delay(tiempo);
  digitalWrite(3, HIGH);
  delay(tiempo);
  digitalWrite(2, LOW);
  delay(tiempo);
  
  digitalWrite(4, HIGH);
  delay(tiempo);
  digitalWrite(3, LOW);
  delay(tiempo);
  digitalWrite(5, HIGH);
  delay(tiempo);
  
  digitalWrite(4, LOW);
  delay(tiempo);
  digitalWrite(6, HIGH);
  delay(tiempo);
  digitalWrite(5, LOW);
  delay(tiempo);
  
  digitalWrite(7, HIGH);
  delay(tiempo);
  digitalWrite(6,LOW);
  delay(tiempo);
 
  // BUCLE FINAL
  digitalWrite(7, LOW);
  delay(tiempo);

  for(int i = 2; i <= 7; i++){
    if(i==2){
      digitalWrite(i, HIGH);
      delay(tiempo);
      digitalWrite(i+1, LOW);
      delay(tiempo);
    }else{
      digitalWrite(i, HIGH);
    }
    
  }
  
  
}
