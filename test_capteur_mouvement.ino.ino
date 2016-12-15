//on initialise le temps de calibration a 30s
int calibrationTime = 30;

int ledPin = 13;                // on choisit le pin 13 pour la led
int inputPin = 2;               // on choisit le pin 2  pour notre capteur de mouvement 
int pirState = LOW;             // Nous commeençons en le mettant sur aucun mouvement detecté
int val = 0;                    // On declare une variable egale a 0 pour lire le statue du Pin 

void setup() {
  pinMode(ledPin, OUTPUT);      // On declare la led en sortie 
  pinMode(inputPin, INPUT);     // On declare le capteur de mouvement en entree
  Serial.begin(9600);

  Serial.print("calibrating sensor ");    // On commence par calibrer notre capteur de mouvement pour avoir une meilleure sensibilité
  for(int i = 0; i < calibrationTime; i++){
    Serial.print(".");
    delay(1000);
  }
}

void loop(){
  val = digitalRead(inputPin);  // On lit la valeur en entree
  Serial.println(val);
  if (val == HIGH) { // Si on detecte un mouvement
    digitalWrite(ledPin, HIGH);  // on allume la led
    delay(150);

    if (pirState == LOW) {
      Serial.println("Motion detected!");
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW); // sinon on eteint la led
    delay(300);
    if (pirState == HIGH){
      Serial.println("Motion ended!");
      pirState = LOW;
    }
  }
}
