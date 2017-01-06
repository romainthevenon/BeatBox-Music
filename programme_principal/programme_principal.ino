#include <Wire.h>
#include "rgb_lcd.h"
#include "pitches.h"

rgb_lcd lcd;

const int colorR = 140;
const int colorG =140;
const int colorB = 255;
int notes[] = {31, 294, 330};

void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,OUTPUT);

  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  digitalWrite(4,HIGH);
  lcd.setCursor(5,0);
  lcd.print(".");
  delay(1000);
  digitalWrite(4,LOW);
  digitalWrite(3,HIGH);
  lcd.print(".");
  delay(1000);
  digitalWrite(3,LOW);
  digitalWrite(2,HIGH);
  lcd.print(".");
  delay(1000);
  digitalWrite(4,HIGH);
  digitalWrite(3,HIGH);
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("Bonjour");
  delay(4000);
}

void loop() {

  lcd.clear();
//Si le bouton 5 est appuyé en premier  
  if (digitalRead(5)==HIGH)
  {
    digitalWrite(2,HIGH);
    if(digitalRead(6)==HIGH)
    {
      digitalWrite(3,HIGH);
      if(digitalRead(7)==HIGH)
      {
        digitalWrite(4,HIGH);
      }
      else
      {
        digitalWrite(4,LOW);
      }
    }
    else if(digitalRead(7)==HIGH)
    {
      digitalWrite(3,LOW);
      digitalWrite(4,HIGH);
    }
    else
    {
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);      
    }
    lcd.print("Bouton 1");
    tone(8,notes[0],250);
    delay(250);
  }

//Si le bouton 6 est appuyé en premier
  else if(digitalRead(6)==HIGH)
  {
    digitalWrite(3,HIGH);
    digitalWrite(2,LOW);
    digitalWrite(4,LOW);
    lcd.print("Bouton 2");
    tone(8,notes[1],250);
    delay(100);
  }
  else if(digitalRead(7)==HIGH)
  {
    digitalWrite(3,LOW);
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    lcd.print("Bouton 3");
    tone(8,notes[2],250);
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
