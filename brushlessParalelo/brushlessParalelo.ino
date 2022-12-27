#include <protothreads.h>

struct pt hilo1;



void setup() {
  // put your setup code here, to run once;
  PT_INIT(&hilo1);

}

void loop() {
  // put your main code here, to run repeatedly:
  parpadeo(&hilo1);
}

void parpadeo(struct pt *pt){

  PT_BEGIN(pt); // Inicio del protothread
  static long t = 0;
  // void setup(){
    pinMode(10, OUTPUT);
  //}
  
  // void loop() {
    do{
      digitalWrite(10, HIGH);
      t = millis();
      // Equivale a un delay(1000);
      PT_WAIT_WHILE(pt, ( millis() - t) < 1000); // Espera por un seg.
      // delay(1000); // Blocante
      digitalWrite(10, LOW);

      PT_WAIT_UNTIL(pt, ( millis() - t) >= 1000); // Espera por un seg.
      // delay(1000); // Blocante
      

      // TAMBIEN ESPERA POR 1SEG
      /* t = millis();
      PT_WAIT_UNTIL(pt, (millis() - t) > 1000); */
    } while(true);
    
  // }

  PT_END(pt);

}
