#define LED 12
#define BUTTON 2


void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*if(digitalRead(BUTTON) == HIGH){
    digitalWrite(LED, HIGH);
  }
  digitalWrite(LED, LOW);
  */
  digitalWrite(LED, digitalRead(BUTTON));
}
