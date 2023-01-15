// PIN ANALOGICO PARA EL SENSOR HALL
int sensorHall = A0;



void setup() {
  // INICIANDO EL MONITOR SERIAL
  Serial.begin(38400);
  Serial.println("SENSOR LISTO");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(sensorHall));
}
