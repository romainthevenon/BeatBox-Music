#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 140;
const int colorG =140;
const int colorB = 255;


void setup() 
{
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    
    lcd.setRGB(colorR, colorG, colorB);
    
}
void loop()
{
  lcd.setCursor(5,0);
  lcd.print("Bonjour");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Passer votre main devant un capteur");  
  delay(1000);
  for(int x=0; x<20; x++) 
  {
    lcd.scrollDisplayLeft(); 
    delay(250);
  }
}
