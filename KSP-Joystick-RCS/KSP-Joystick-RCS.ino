#include "Keyboard.h"

void setup() {
  // open the serial port:
  Serial.begin(9600);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  if (analogRead(0) > 621) {
    Keyboard.print("j");
    delay(map(analogRead(0), 621, 1023, 200, 60));
  } else if (analogRead(0) < 419) {
    Keyboard.print("l");
    delay(map(analogRead(0), 0, 419, 60, 200));
  }
  
  if (analogRead(1) > 603) {
    Keyboard.print("n");
    delay(map(analogRead(1), 603, 1023, 200, 60));
  } else if (analogRead(1) < 401) {
    Keyboard.print("h");
    delay(map(analogRead(1), 0, 401, 60, 200));
  }

  if (analogRead(2) > 603) {
    Keyboard.print("i");
    delay(map(analogRead(2), 603, 1023, 200, 60));
  } else if (analogRead(2) < 401) {
    Keyboard.print("k");
    delay(map(analogRead(2), 0, 401, 60, 200));
  }
}
