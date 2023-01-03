// 
int led = 2;
int state = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  // VERIFICAR SI EL PUERTO SERIAL ESTA HABILITADO
  if(Serial.available() > 0){
    state = Serial.read();
  }

  switch(state){
    case 'E' :
      digitalWrite(led, HIGH);
      state = 0;
    break;
    case 'A' :
      digitalWrite(led, LOW);
      state = 0;
    break;
  }

}
