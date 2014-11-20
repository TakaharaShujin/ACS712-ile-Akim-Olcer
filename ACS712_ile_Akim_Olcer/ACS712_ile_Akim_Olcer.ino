#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  lcd.begin(16,2);
 Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);    
  int premap = map(sensorValue, 0, 1024, -2300, 2300);
  
  float vysledok = premap / float(185);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Gecen amper :");
  lcd.setCursor(0,1);
  lcd.print(vysledok);
  delay(500);
}
