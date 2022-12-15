int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;

int numeros[9][7] = {
  {0, 1, 1, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 1},
  {1, 1, 1, 1, 0, 0, 1},
  {0, 1, 1, 0, 0, 1, 1},
  {1, 0, 1, 1, 0, 1, 1},
  {1, 0, 1, 1, 1, 1, 1},
  {1, 1, 1, 0, 0, 0, 1},
  {1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 0, 0, 1, 1}
};

void mostrarNumero(int bits, int inicio, int fin){
  int led = 0;
  for(int i = inicio; i <= fin; i++){
    digitalWrite(i, numeros[led,] );
    delay(500);
  }
}

void setup() {
  // Configurar cada uno de los pines como salida
  Serial.begin(9600);

  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  Serial.println( sizeof(numeros) );  
  Serial.println( sizeof(numeros)/sizeof(numeros[0]) );  
}

void loop() {

  mostrarNumero(numeros, 2, 8);
  // Mostrar el número "1" en el display de 7 segmentos
	// 0, 1, 1, 0, 0, 0, 0
  /* digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  delay(1000); */


  // Mostrar el número "2" en el display de 7 segmentos
	// 1, 1, 0, 1, 1, 0, 1
  /* digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
  delay(1000); */

  // Mostrar el número "3" en el display de 7 segmentos
	// 1, 1, 1, 1, 0, 0, 1
  /* digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
  delay(1000); */
}