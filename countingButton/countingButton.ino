#define BUTTON 2

int count;
bool buttonAlreadyOn;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON, INPUT);
  buttonAlreadyOn = false;
  count = 0;
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = digitalRead(BUTTON);
  if(buttonState == HIGH && !buttonAlreadyOn){
    Serial.println(String("Counter is: ") + (++count));
    buttonAlreadyOn = true;
  } else if(buttonState == LOW && buttonAlreadyOn){
    buttonAlreadyOn = false;
  }
}
