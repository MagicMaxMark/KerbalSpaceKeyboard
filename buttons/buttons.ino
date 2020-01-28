#include "Keyboard.h"

bool RCS = false;
bool SAS = false;

void setup() {
  Keyboard.begin();
  
  for (int i = 4; i <= 12; i++){
    pinMode(i, INPUT_PULLUP);
  }

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);rrttrr
}

void loop() {
  for (int i = 7; i <= 12; i++){
    if (digitalRead(i) == LOW){
      char letter;
      if(i == 5){
        letter = 'c';
      } else if(i == 6){
        letter = 'm';
      } else if(i == 7){
        letter = 'g';
      } else if(i == 8){
        letter = 'u';
      } else if(i == 9){
        if (digitalRead(4) == LOW){
          letter = KEY_BACKSPACE;
        }
      } else if(i == 10){
        if (digitalRead(4) == LOW){
          letter = ' ';
        }
      } else if(i == 11){
        letter = 't';
        if (SAS == false){
          SAS = true;
        } else {
          SAS = false;
        }
      } else if(i == 12){
        letter = 'r';
        if (RCS == false){
          RCS = true;
        } else {
          RCS = false;
        }
      }
      Keyboard.print(letter);
    }
  }
  delay(200);
  if (RCS == true){
    digitalWrite(3, HIGH);
  } else {
    digitalWrite(3, LOW);
  }
  
  if (SAS == true){
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
}
