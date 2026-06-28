#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Hello");
  delay(500);
  lcd.print(" World");
  delay(500);
  lcd.clear();
  delay(100);
}
