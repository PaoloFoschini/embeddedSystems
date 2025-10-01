#define LED 13

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED, HIGH);
  Serial.println("ON");
  delay(1000);
  digitalWrite(LED, LOW);
  Serial.println("OFF");
  delay(1000);
}
