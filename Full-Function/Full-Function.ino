#include "Keyboard.h"

int pos = 0;

void setup() {
  Serial.begin(9600);
  
  Keyboard.begin();

}

void loop() {
  //Steering Joystick
  if (analogRead(0) > 621) {
    Keyboard.print("d");
    delay(map(analogRead(0), 621, 1023, 300, 200));
  } else if (analogRead(0) < 419) {
    Keyboard.print("a");
    delay(map(analogRead(0), 0, 419, 200, 300));
  }
  
  if (analogRead(1) > 603) {
    Keyboard.print("s");
    delay(map(analogRead(1), 603, 1023, 300, 200));
  } else if (analogRead(1) < 401) {
    Keyboard.print("w");
    delay(map(analogRead(1), 0, 401, 200, 300));
  }


  //Throttle Slider
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
  }
}
