#include "Keyboard.h"

bool RCS = false;
bool SAS = false;
bool currentStates[] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};

void setup() {
  Keyboard.begin();
  
  for (int i = 4; i <= 12; i++){
    pinMode(i, INPUT_PULLUP);
  }

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  for (int i = 7; i <= 12; i++){
    if (digitalRead(i) == LOW){
      char letter;
      if(i == 5 && currentStates[0] == HIGH){
        letter = 'c';
        currentStates[0] == LOW;
      } else if(i == 6 && currentStates[1] == HIGH){
        letter = 'm';
        currentStates[1] == LOW;
      } else if(i == 7 && currentStates[2] == HIGH){
        letter = 'g';
        currentStates[2] == LOW;
      } else if(i == 8 && currentStates[3] == HIGH){
        letter = 'u';
        currentStates[3] == LOW;
      } else if(i == 9 && currentStates[4] == HIGH && digitalRead(4) == LOW){
        letter = KEY_BACKSPACE;
        currentStates[4] == LOW;
      } else if(i == 10 && currentStates[5] == HIGH && digitalRead(4) == LOW){
        letter = ' ';
        currentStates[5] == LOW;
      } else if(i == 11 && currentStates[6] == HIGH){
        letter = 't';
        if (SAS == false){
          SAS = true;
        } else {
          SAS = false;
        }
        currentStates[6] == LOW;
      } else if(i == 12 && currentStates[8] == HIGH){
        letter = 'r';
        if (RCS == false){
          RCS = true;
        } else {
          RCS = false;
        }
        currentStates[8] == LOW;
      }
      Keyboard.print(letter);
    }
    Serial.println(digitalRead(i));
  }
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
