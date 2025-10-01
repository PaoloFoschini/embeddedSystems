#define LED 11

  int currentVal = 0;
  int fadingVal = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(LED, currentVal);
  currentVal+=fadingVal;
  if(currentVal == 0 || currentVal == 255){
    fadingVal = -fadingVal;
  }
  
  
  Serial.println(currentVal);
  delay(30);
}
