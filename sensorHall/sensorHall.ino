// VARIABLES DE ENTRADA
int pinAnalogOut = A0;
int flujoMagneticoLeido = 0;
int flujoMagneticoMedido = 0;



void setup() {
  // Iniciando el Monitor Serial
  Serial.begin(9600);
  Serial.println("SENSOR LISTO PARA INICIALIZARLA");
}

void loop() {
  // put your main code here, to run repeatedly:
  flujoMagneticoLeido = analogRead(pinAnalogOut);
  flujoMagneticoMedido = 3.7*flujoMagneticoLeido - 1937;
  Serial.print("Campo Magnético:" );
  Serial.print(flujoMagneticoMedido);
  Serial.print(" G \n");
  delay(1000);
}
