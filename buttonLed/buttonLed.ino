#define LED 12
#define BUTTON 2

bool ledAlreadyOn;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  ledAlreadyOn = false;
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  /*if(digitalRead(BUTTON) == HIGH){
    digitalWrite(LED, HIGH);
  }
  digitalWrite(LED, LOW);
  */
  //digitalWrite(LED, digitalRead(BUTTON));
  int buttonState = digitalRead(BUTTON);
  if(buttonState == HIGH && !ledAlreadyOn){
    Serial.println("PRESSED");
    digitalWrite(LED, HIGH);
    ledAlreadyOn = true;
  } else if(buttonState == LOW && ledAlreadyOn){
    Serial.println("RELEASED");
    digitalWrite(LED, LOW);
    ledAlreadyOn = false;
  }
}
