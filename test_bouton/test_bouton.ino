#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 140;
const int colorG =140;
const int colorB = 255;

void setup() {
  Serial.begin(9600);
  pinMode(3, INPUT);
  pinMode(2,OUTPUT);
  pinMode(6,OUTPUT);
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);

  lcd.setCursor(5,0);
  lcd.print("Bonjour");
  delay(4000);
  lcd.clear();

}

void loop() {
  if(digitalRead(3) == LOW)
  {
    lcd.clear();
    lcd.print("bouton ok");
    digitalWrite(2,HIGH);
    digitalWrite(6,HIGH);
    delay(50);
  }
  else
  {
    lcd.clear();
    lcd.print("bouton non ok");
    digitalWrite(2,LOW);
    digitalWrite(6,LOW);
    delay(50);
  }


}
