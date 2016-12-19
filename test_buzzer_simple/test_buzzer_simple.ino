void setup() {
  // put your setup code here, to run once:
  pinMode(6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(6,HIGH);
  delay(analogRead(0));
  digitalWrite(6,LOW);
  delay(analogRead(0));
}
