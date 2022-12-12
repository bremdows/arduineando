template<class T> inline Print &operator <<(Print &obj, T arg) { obj.print(arg); return obj; }
// PINES PARA EL CONTROL DEL MOTOR
int EN1 = 8;
int EN2 = 9;


// EXTREMOS DE LAS BOBINAS
int IN1 = 2;
int IN2 = 3;
int IN3 = 4;
int IN4 = 5;

// VARIABLES DE CONTROL
char dataSerial;
char direccion;
int velocidad = 1;

String saludo = "Hola Mundo";
void setup() {
  // ACTIVANDO EL MONITOR SERIAL - COMUNICACIÓN SERIAL
  Serial.begin(9600);
  

  // DEFINIENDO LAS SALIDAS
  for( int i = 2; i <= 5; i++){
    pinMode(i, OUTPUT);
  }
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
    
}

void loop() {
  // RECIBIENDO DATOS DESDE EL MONITOR SERIAL
  dataSerial = Serial.read();
  switch(dataSerial){
    case '+': 
      direccion = 'R';
    break;
    case '-':
      direccion = 'L';
    break;
    case '1' :
      velocidad = 1;
    break;
    case '2' :
      velocidad = 2;
    break;
    case '3' :
      velocidad = 3;
    break;
  }
  // Serial.println("La direccion es:" + direccion);
  Serial.println(direccion);
  Serial << "La velocidad es: " << velocidad << "\n";

  delay(1000);

}































