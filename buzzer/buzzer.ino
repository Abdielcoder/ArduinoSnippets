#include "pitches.h"  //libreria que tiene los pulsos de la melodia
//Led
int led = 2;

//notas de la melodia
int melody[]={NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};

//digital pin 12 has a button attached to it. Give it an name
int buttonPin= 12;

//duracion nora. 4=quarter note / 8=eighth note
int noteDurations[]={4, 8, 8, 4, 4, 4, 4, 4};


void setup(){
   //Led
   pinMode(led,OUTPUT);
  //make the button's pin input
  pinMode(buttonPin, INPUT);
}


void loop(){

  //Leyendo el input digital
  int buttonState = digitalRead(buttonPin);

  //Si el boton se presiona
  if (buttonState == 1){

    //Itera las notas de la melodia
    for (int thisNote=0; thisNote <8; thisNote++){
      //ENCEDER LED
      digitalWrite(led, HIGH);
      
      //Calculando la duracion de la nota
      int noteDuration = 1000 / noteDurations [thisNote];
      tone(8, melody [thisNote], noteDuration);

      //Tiempo de duracion entre notas
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      //para de reproducir
      noTone(8);
      //apagar led
       digitalWrite(led, LOW);
    }
  }
}
          
          
     
