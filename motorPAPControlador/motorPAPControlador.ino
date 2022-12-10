/*
  PULSADORES
*/
byte pHorario  = 2;
byte pAntihorario = 3;
byte pPasos = 4;
byte pVel = 5;

/*
  PINES DEL CONTROLADOR
*/
byte IN1=8;  // 28BYJ48 In1
byte IN2=9;  // 28BYJ48 In2
byte IN3=10; // 28BYJ48 In3
byte IN4=11; // 28BYJ48 In4

int horario = 1;

int paso = 4;
int cPaso = 0;
int vel[5] = {5, 10, 30, 100, 500};
int cVel = 0;
int config = 1;

/* 
  MATRIZ PARA EL CONTROL DEL MOVIMIENTO SEGÚN UNA SECUENCIA DETERMINADA
*/
const int unPaso[4] = {
  B1000,
  B0100,
  B0010,
  B0001
};

const int dosPasos[4] = {
  B1100,
  B0110,
  B0011,
  B1001
};

byte const medioPaso[8] = {
  B1000,
  B1100,
  B0100,
  B0110,
  B0010,
  B0011,
  B0001,
  B1001
};

/* 
  FUNCIONES
*/

// Función que coloca en el puerto de salida los bits comenzando
// desde el pin ini hasta el pin fin

void puerto(int bits, int ini, int fin){
  for(int i = ini; i <= fin; i++){
    digitalWrite(i, bitRead(bits, i-ini));
  }
}


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
