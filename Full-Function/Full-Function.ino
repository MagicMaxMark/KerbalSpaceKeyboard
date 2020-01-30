#include "Keyboard.h"

int pos = 0;

void setup() {
  Serial.begin(9600);
  
  Keyboard.begin();

  for (int i = 4; i <= 12; i++){
    pinMode(i, INPUT_PULLUP);
  }

}

void loop() {
  //Steering Joystick
  if (analogRead(0) > 621) {
    Keyboard.print("a");
    delay(map(analogRead(0), 621, 1023, 200, 60));
  } else if (analogRead(0) < 419) {
    Keyboard.print("d");
    delay(map(analogRead(0), 0, 419, 60, 200));
  }
  
  if (analogRead(1) > 603) {
    Keyboard.print("s");
    delay(map(analogRead(1), 603, 1023, 200, 60));
  } else if (analogRead(1) < 401) {
    Keyboard.print("w");
    delay(map(analogRead(1), 0, 401, 60, 200));
  }

  if (analogRead(2) > 603) {
    Keyboard.print("e");
    delay(map(analogRead(2), 603, 1023, 200, 60));
  } else if (analogRead(2) < 401) {
    Keyboard.print("q");
    delay(map(analogRead(2), 0, 401, 60, 200));
  }

  /*RCS Joystick*/

  if (analogRead(3) > 621) {
    Keyboard.print("j");
    delay(map(analogRead(3), 621, 1023, 200, 60));
  } else if (analogRead(3) < 419) {
    Keyboard.print("l");
    delay(map(analogRead(3), 0, 419, 60, 200));
  }
  
  if (analogRead(4) > 603) {
    Keyboard.print("n");
    delay(map(analogRead(4), 603, 1023, 200, 60));
  } else if (analogRead(4) < 401) {
    Keyboard.print("h");
    delay(map(analogRead(4), 0, 401, 60, 200));
  }

  if (analogRead(5) > 603) {
    Keyboard.print("i");
    delay(map(analogRead(5), 603, 1023, 200, 60));
  } else if (analogRead(5) < 401) {
    Keyboard.print("k");
    delay(map(analogRead(5), 0, 401, 60, 200));
  }

  /*//Throttle Slider
  while (pos < map(analogRead(2), 0, 1023, 0, 10)){
    pos ++;
    Keyboard.press(KEY_LEFT_SHIFT);
    delay(40);
    Keyboard.release(KEY_LEFT_SHIFT);
  }
  while (pos > map(analogRead(2), 0, 1023, 0, 10)){
    pos --;
    Keyboard.print(KEY_LEFT_CTRL);
    delay(40);
    Keyboard.release(KEY_LEFT_CTRL);
  }

  if (pos == 0){
    Keyboard.print("x");
  }
  if (pos == 10){
    Keyboard.print("z");
  }*/

  //Buttons for m, c, space, backspace, t, r, u, g

  for (int i = 5; i <= 12; i++){
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
      } else if(i == 12){
        letter = 'r';
      }
      Keyboard.print(letter);
      delay(250);
    }
  }
  
}
