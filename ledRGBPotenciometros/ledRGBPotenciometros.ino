template<class T> inline Print &operator <<(Print &obj, T arg) { obj.print(arg); return obj; }
// POTENCIOMETRO
int pot1 = A0;
int pot2 = A1;
int pot3 = A2;

int potValue1 = 0;
int potValue2 = 0;
int potValue3 = 0;

// LEDS
int led1 = 9;
int led2 = 10;
int led3 = 11;

int light1 = 0;
int light2 = 0;
int light3 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  
  potValue1 = analogRead(pot1);
  potValue2 = analogRead(pot2);
  potValue3 = analogRead(pot3);

  // Reduciendo el valor MAX del potenciometro 1023 a 255 que es máximo valor para una salida PWM
  light1 = map(potValue1, 0, 1023, 0, 255);
  light2 = map(potValue2, 0, 1023, 0, 255);
  light3 = map(potValue3, 0, 1023, 0, 255);

  analogWrite(led1, light1);
  analogWrite(led2, light2);
  analogWrite(led3, light3);

  Serial << "Pot 1: " << potValue1 << "\n";
  Serial << "Luminosidad 1: " << light1 << "\n";

  Serial << "Pot 2: " << potValue2 << "\n";
  Serial << "Luminosidad 2: " << light2 << "\n";
  
  Serial << "Pot 3: " << potValue3 << "\n";
  Serial << "Luminosidad 3: " << light3 << "\n";
  
}
