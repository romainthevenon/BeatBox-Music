#include "pitches.h" // inclusion du fichier de notes

// tableau de mémorisation des notes de la mélodie
int melody[] = {
  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

// tableau de mémorisation de la durée des notes : 4 = noire, 8 = croche, etc.:
int noteDurations[] = {
  4, 8, 8, 4,4,4,4,4 };

void setup() {
  // boucle pour parcourir les notes de la mélodie
  for (int thisNote = 0; thisNote < 8; thisNote++) { // thisNote de 0 à 7

    // pour calculer la durée de la note, on divise 1 seconde par le type de la note
    //ainsi noire = 1000 / 4 sec, croche = 1000/8 sec, etc...
    int noteDuration = 1000/noteDurations[thisNote];

    // joue la note sur la broche 8 pendant la durée voulue
    tone(8, melody[thisNote],noteDuration);

    // pour distinguer les notes, laisser une pause entre elles
    // la durée de la note + 30% fonctionne bien :
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes); // delai entre les notes

    // stoppe la production de son sur la broche 8 :
    noTone(8);
  }
}

void loop() {

// vide : la mélodie n'est pas répétée

}
