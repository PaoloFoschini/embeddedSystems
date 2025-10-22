#include <LiquidCrystal_I2C.h> 

/* Wiring: SDA => A4, SCL => A5 */
/* I2C address of the LCD: 0x27 */
/* Number of columns: 20 rows: 4 */
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27,20,4); 

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  lcd.setCursor(0, 0); // Set the cursor on the third column and first row.
  if (Serial.available()){
    String data = Serial.readString();
    Serial.print(data);
    String message = "";
    message += data;
    lcd.clear(); // Pulisce lo schermo prima di scrivere
    message.remove(message.length() - 1);
    lcd.print(message);
  }  
}
