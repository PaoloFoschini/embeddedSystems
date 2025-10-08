#include <EnableInterrupt.h>
#define BUTTON 6 // funziona solo perchè usiamo libreria enable interrupt
//#define DEBOUNCE_TIME 200


volatile int count = 0;
int prev;
//int prevts;
//int numFiltered;

void setup() {
  Serial.begin(9600);
  //attachInterrupt(digitalPinToInterrupt(BUTTON), inc, RISING);
  enableInterrupt(BUTTON, inc, RISING);
  prev = 0;
  //prevts = 0;
  //numFiltered = 0;
}

void loop() {
  noInterrupts(); // questo lo facciamo per essere sicuri che count non venga modificata da nessun altro, prevediamo race conditions
  int current = count;
  interrupts(); 
  if(current != prev){
    Serial.println(String(current));// + " " + numFiltered + " " + prevts);
    prev = current;
  }
}

void inc(){
  //long ts = millis();
  /*if(ts - prevts > DEBOUNCE_TIME){
    count++;
    prevts = ts;
  }*/
  //numFiltered++;
  count++;
}
