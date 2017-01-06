#include <Wire.h>
#include "rgb_lcd.h"
#include "pitches.h"

rgb_lcd lcd;

const int colorR = 140;
const int colorG =140;
const int colorB = 255;
int notes[] = {31, 294, 330};
int melody[] = {
  NOTE_C3, 0, NOTE_G3, 0,NOTE_G3, NOTE_F3, NOTE_G3, 0, NOTE_F3, NOTE_DS3, NOTE_F3, 0, NOTE_F3, NOTE_DS3, NOTE_D3, NOTE_DS3};

int melody_2[] = {
  NOTE_AS3, NOTE_C4, NOTE_CS4,0, NOTE_C4, NOTE_AS3, NOTE_C4, NOTE_CS4, NOTE_DS4, NOTE_C4, NOTE_CS4, NOTE_C4, NOTE_AS3,0,0,0, NOTE_CS4, NOTE_DS4, NOTE_F4,0, NOTE_DS4, NOTE_CS4, NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_F4,0,0,0,0,0,0,NOTE_F4 ,NOTE_GS4, NOTE_AS4,0, NOTE_GS4, NOTE_FS4, NOTE_F4, NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_GS4,0, NOTE_CS4,0, NOTE_AS3,0, NOTE_AS3, NOTE_C4, NOTE_CS4,0, NOTE_C4, NOTE_AS3, NOTE_DS4, NOTE_CS4, NOTE_C4, NOTE_AS3 };

int melody_3[] = {
  NOTE_F4, NOTE_F4, NOTE_F4,0, NOTE_AS4, NOTE_AS4,0,0,0,0,0,0,0,0,0,0, NOTE_F4, NOTE_F4, NOTE_F4,0, NOTE_C5, NOTE_C5,0,0,0,0,0,0,0,0,0,0, NOTE_C5,0, NOTE_CS5,0, NOTE_AS4,0,0,0,0,0,0,0,0,0,0,0 ,NOTE_C5,0,NOTE_CS5,0 ,NOTE_AS4,0,0,0,0,0,0,0,NOTE_A4 };
  int noteDurations[] = {
  4,4,4,4,4,4,4,4,4,4,4,4,2,8,4,4,4,4,4,4,4,4,4,4,4,1,16,4,4,4,4,4,4,4,2,8,4,4,4,4,4,4,2,8,2,8,2,8,4,4,2,8,4,4,4,4,4,1};


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
  for (int thisNote = 0; thisNote < 61; thisNote++) { // thisNote de 0 à 7

    // pour calculer la durée de la note, on divise 1 seconde par le type de la note
    //ainsi noire = 1000 / 4 sec, croche = 1000/8 sec, etc...
   // int noteDuration = 1000/noteDurations[thisNote];
   int noteDuration = 1000/8;

    // joue la note sur la broche 8 pendant la durée voulue
    tone(8, melody_3[thisNote],noteDuration);

    // pour distinguer les notes, laisser une pause entre elles
    // la durée de la note + 30% fonctionne bien :
    int pauseBetweenNotes = noteDuration * 0.90;
    delay(pauseBetweenNotes); // delai entre les notes

    // stoppe la production de son sur la broche 8 :
    noTone(8);
  }
    delay(250);
  }

//Si le bouton 6 est appuyé en premier
  else if(digitalRead(6)==HIGH)
  {
    digitalWrite(3,HIGH);
    digitalWrite(2,LOW);
    digitalWrite(4,LOW);
    lcd.print("Bouton 2");
  for (int thisNote = 0; thisNote < 58; thisNote++) { // thisNote de 0 à 7

    // pour calculer la durée de la note, on divise 1 seconde par le type de la note
    //ainsi noire = 1000 / 4 sec, croche = 1000/8 sec, etc...
   // int noteDuration = 1000/noteDurations[thisNote];
   int noteDuration = 1000/4;

    // joue la note sur la broche 8 pendant la durée voulue
    tone(8, melody_2[thisNote],noteDuration);

    // pour distinguer les notes, laisser une pause entre elles
    // la durée de la note + 30% fonctionne bien :
    int pauseBetweenNotes = noteDuration * 1.15;
    delay(pauseBetweenNotes); // delai entre les notes

    // stoppe la production de son sur la broche 8 :
    noTone(8);
  }
    delay(100);
  }
  else if(digitalRead(7)==HIGH)
  {
    digitalWrite(3,LOW);
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    lcd.print("Bouton 3");
  for (int thisNote = 0; thisNote < 16; thisNote++) { // thisNote de 0 à 7

    // pour calculer la durée de la note, on divise 1 seconde par le type de la note
    //ainsi noire = 1000 / 4 sec, croche = 1000/8 sec, etc...
   // int noteDuration = 1000/noteDurations[thisNote];
   int noteDuration = 1000/4;

    // joue la note sur la broche 8 pendant la durée voulue
    tone(8, melody[thisNote],noteDuration);

    // pour distinguer les notes, laisser une pause entre elles
    // la durée de la note + 30% fonctionne bien :
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes); // delai entre les notes

    // stoppe la production de son sur la broche 8 :
    noTone(8);
  }
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
