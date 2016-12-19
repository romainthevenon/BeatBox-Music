#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 140;
const int colorG =140;
const int colorB = 255;

void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);

  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);

  lcd.setCursor(5,0);
  lcd.print("Bonjour");
  delay(4000);

}

void loop() {

  lcd.clear();  
  if (digitalRead(5)==HIGH)
  {
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    lcd.print("Bouton 1");
    delay(250);
  }
  else if(digitalRead(6)==HIGH)
  {
    digitalWrite(3,HIGH);
    digitalWrite(2,LOW);
    digitalWrite(4,LOW);
    lcd.print("Bouton 2");
    delay(100);
  }
  else if(digitalRead(7)==HIGH)
  {
    digitalWrite(3,LOW);
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    lcd.print("Bouton 3");
    delay(100);
  }
  else
  {
    digitalWrite(3,LOW);
    digitalWrite(2,LOW); 
    digitalWrite(4,LOW);
    lcd.setCursor(1,0); 
    lcd.print("Appuyer sur un");
    lcd.setCursor(4,1);
    lcd.print("bouton");
    delay(100);  
  }
  

}
