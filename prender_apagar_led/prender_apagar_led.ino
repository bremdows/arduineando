// INICIALIZAR DEFINIR UN PUERTO COMO ENTRADA O SALIDA

// INPUT = ENTRADA (RECIBIR SEÑAL)
// OUTPUT = SALIDA (ENVIAR SEÑAL)
// HIGH = PARA ENVIAR 1 /prender
// LOW = PARA ENVIAR 0 /apagar

// DECLARAR UN ARREGLO

const int lista[] = {2, 3, 4, 5, 6, 7};
float tiempo = 500;
int n;

// El SETUP es como nuestra caja de inicialización
void setup(){

  for(n = 0; n < 6; n++){
    pinMode(lista[n], OUTPUT);
  }
  // PARA ACTIVAR UN PIN, 1ER: NUM_PIN, 2DO: SI ES SALIDA O ENTRADA
  pinMode(2, OUTPUT);
  
}

// FUNCIÓN QUE NUNCA DEJA FUNCIONAR 
void loop(){
  lucesArreglo();
}


void lucesArreglo(){
  for(n = 0; n < 6; n++){
    digitalWrite(lista[n], HIGH);
    delay(tiempo);
    digitalWrite(lista[n], LOW);
    delay(tiempo);
  }
  
}

void luces(){
     // Para enviar señales 1ER: NUM_PIN, 2DO: VALOR DE ENCENDIDO O APAGADO (HIGH, LOW)
    digitalWrite(2, HIGH);
    
    // retrasar los tiempos de ejecución, se hace uso de milisegundos
    delay(450);

    // Para enviar la señal de apagad

    digitalWrite(2, LOW);

    // VOLVER A APLICAR UN RETRASO
    delay(tiempo);
}

void brazo_izquierdo(){
  // Código para mover el brazo izquierdo
}

void brazo_derecho(){
  // Código
}
