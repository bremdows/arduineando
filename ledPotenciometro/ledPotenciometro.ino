int led = 4;
int analogPot = A0;
int potValue = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT); // pinMode solo se utiliza para pines Digitales

}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead( analogPot );
  Serial.println( potValue );
  digitalWrite(led, HIGH);
  delay(potValue);
  digitalWrite(led, LOW);
  delay(potValue);

}
