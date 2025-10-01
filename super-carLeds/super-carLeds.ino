#define LED1 13
#define LED2 12
#define LED3 8
#define LED4 7

int leds[4] = { LED1, LED2, LED3, LED4 }; 
int currentLED = 0;
int step = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(leds[currentLED], HIGH);
  delay(150);
  digitalWrite(leds[currentLED], LOW);
  currentLED += step;
  if(currentLED == 3 || currentLED == 0){
    step = -step;
  }
}
