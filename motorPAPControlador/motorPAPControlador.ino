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
    digitalWrite(i, bitRead(bits, i - ini));
  }
}


void setup() {
  // put your setup code here, to run once:
  for(int i = 2; i <= 5; i++){
    pinMode(i, INPUT);
  }

  for(int i = IN1; i <= IN4; i++){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  //******************************************************************************//
  //***********    Pregunta por los Pulsadores   *********************************//
  //******************************************************************************//
  
  // Giro en Sentido Horario
  if(digitalRead(pHorario))  // Pregunta si pulsador horario fue presionado
  {
    delay(100); //Anti-Rebote
    horario=1;
    Cpaso=-1;
  }
  // Giro en Sentido Anti-Horario
  if(digitalRead(pAntiHorario))  // Pregunta si pulsador horario fue presionado
  {
    delay(100); //Anti-Rebote
    horario=0;
    Cpaso=paso;
  }
  // Cambio de la secuencia de pasos
  if(digitalRead(PPasos))  // Pregunta si pulsador horario fue presionado
  {
    delay(100); //Anti-Rebote
    while(digitalRead(PPasos)); //Espera hasta soltar el boton
    delay(100); //Anti-Rebote
    conf++;
    //Si ya paso por las 3 configuraciones reinicie
    if(conf>3)
      conf=1;
    if(horario==1)
      Cpaso=-1;
    else
      Cpaso=paso;
    puerto(B0000,IN1,IN4);
  }
  // Velocidad del Motor
  if(digitalRead(PVel))  // Pregunta si pulsador horario fue presionado
  {
    delay(100); //Anti-Rebote
    while(digitalRead(PVel)); //Espera hasta soltar el boton
    delay(100); //Anti-Rebote
    Cvel++;
    //Si ya paso por las 5 velocidades reinicie
    if(Cvel>4)
      Cvel=0;
  }
  //******************************************************************************//
  //***********    Logica de los contadores      *********************************//
  //******************************************************************************//
  if(horario == 1)
  {
    Cpaso++;                        //Incremente la variable cont
    if(Cpaso >= paso)
       Cpaso=0;                          //Se pone Contador de pasos en cero 
  } 
  else{
    Cpaso--;                        //Decremente la variable cont
    if(Cpaso<0)
      Cpaso=paso-1;                  //Se pone Contador igual al paso
  }
  
  //******************************************************************************//
  //***********    Secuencia de Movimiento del Motor   ***************************//
  //******************************************************************************//
    switch(conf){
      case 1:
              puerto(UnPaso[Cpaso],IN1,IN4); //Envíe al puerto la información de la tabla
              paso=4;
              break;
      case 2:
              puerto(DosPasos[Cpaso],IN1,IN4); //Envíe al puerto la información de la tabla
              paso=4;
              break;
      case 3:
              puerto(MedioPaso[Cpaso],IN1,IN4); //Envíe al puerto la información de la tabla
              paso=8;
              break;
    }
    delay(vel[Cvel]);                      //Retardo de 100 milisegundos  
}
































