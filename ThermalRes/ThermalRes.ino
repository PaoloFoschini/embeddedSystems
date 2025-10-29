const int sensorPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(sensorPin);
  float voltage = reading * 5.0 / 1023.0; // se alimentato a 5V
  float temperatureC = (voltage - 0.5) * 100;
  Serial.print("Temperatura: ");
  Serial.print(temperatureC);
  Serial.println(" °C");
  delay(1000);
}
