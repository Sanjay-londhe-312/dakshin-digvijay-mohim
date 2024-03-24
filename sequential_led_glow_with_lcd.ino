#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int leds[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1, A2};
int num_leds = sizeof(leds) / sizeof(leds[0]);
char *fort_names[] = {"Raigad Fort", "Pratapgad Fort", "Satara", "Kopal", "Mallikarjun Temple", "Govalkonda Fort", "Jinjee Fort", "Vellore Fort", "Kaken & Kaveri River", "Penukond Fort", "Maisur kinarpatti", "Belawadi", "Panhala Fort", "Sajjangad Fort", "Pratapgad vrti puja"};
char *build_dates[] = {"date jan 1677", "date jan 1677", "Date jan 1677", "Date feb 1677", "date apr 1677", "Date 1677", "Date G", "date june 1677", "date jul 1677", "date nov 1677 ", "Date nov 1677", "Date dec 1677", "Date march 1678", "Date march 1678", "Date april 1678"};

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Dhakshin digviay");
  lcd.setCursor(0, 1);
  lcd.print("         mohim");
  
  delay(5000);
  
  for (int i = 0; i < num_leds; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < num_leds; i++) {
    digitalWrite(leds[i], HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(fort_names[i]);
    lcd.setCursor(0, 1);
    lcd.print(build_dates[i]);
    
    Serial.print("LED ");
    Serial.print(i + 1);
    Serial.print(" is ON: ");
    Serial.print(fort_names[i]);
    Serial.print(" - ");
    Serial.println(build_dates[i]);

    delay(8000);

    // Do not turn off the LED here
  }
  
  // Turn off all LEDs
  for (int i = 0; i < num_leds; i++) {
    digitalWrite(leds[i], LOW);
  }
  
  
}
