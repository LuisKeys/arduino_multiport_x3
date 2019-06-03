#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x3F
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

void writeLCDClear(byte val) {
  lcd.clear();  
  lcd.home();  
  lcd.print("Valor Leido:");
  lcd.setCursor (0,1);  
  lcd.print(val);
}

void initLCD() {
  lcd.begin (16,2);
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
  writeLCDClear(0);

}

void writeLCD(byte val) {
  lcd.setCursor (0,1);  
  lcd.print("    ");
  lcd.setCursor (0,1);  
  lcd.print(val);
}

void writeLCD(byte val1, byte val2, byte val3) {
  lcd.setCursor (0,1);
  lcd.print("                      ");
  lcd.setCursor (0,1);  
  lcd.print(val1);

  lcd.setCursor (6,1);  
  lcd.print(val2);

  lcd.setCursor (10,1);  
  lcd.print(val3);
}
