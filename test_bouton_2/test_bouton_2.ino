void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);

}

void loop() {
  if (digitalRead(5)==HIGH)
  {
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
  }
  else if(digitalRead(6)==HIGH)
  {
    digitalWrite(3,HIGH);
    digitalWrite(2,LOW);
    digitalWrite(4,LOW);
  }
  else if(digitalRead(7)==HIGH)
  {
    digitalWrite(3,LOW);
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
  }
  else
  {
    digitalWrite(3,LOW);
    digitalWrite(2,LOW); 
    digitalWrite(4,LOW);   
  }
  

}
