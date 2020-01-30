#include "Keyboard.h"

bool pin12 = true;
bool pin11 = true;
bool pin10 = true;
bool pin9  = true;

void setup() {
  // open the serial port:
  Serial.begin(9600);
  // initialize control over the keyboard:
  Keyboard.begin();

  pinMode(12, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(12) == LOW && pin12 == true){
    Keyboard.print('z');
  } else if (digitalRead(11) == LOW && pin11 == true){
    Keyboard.print(KEY_LEFT_SHIFT);
  } else if (digitalRead(10) == LOW && pin10 == true){
    Keyboard.print(KEY_LEFT_CTRL);
  } else if (digitalRead(9) == LOW && pin9 == true){
    Keyboard.print('x');
  }

  pin12 = digitalRead(12);
  pin11 = digitalRead(11);
  pin10 = digitalRead(10);
  pin9 = digitalRead(9);
}
