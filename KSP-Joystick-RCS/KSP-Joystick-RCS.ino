#include "Keyboard.h"

int keyPressDelayMin = 60;
int keyPressDelayMax = 200;

void setup() {
  // open the serial port:
  Serial.begin(9600);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  if (analogRead(3) > 621) {
    Keyboard.print("j");
    delay(map(analogRead(3), 621, 1023, keyPressDelayMax, keyPressDelayMin));
  } else if (analogRead(3) < 419) {
    Keyboard.print("l");
    delay(map(analogRead(3), 0, 419, keyPressDelayMin, keyPressDelayMax));
  }
  
  if (analogRead(4) > 603) {
    Keyboard.print("n");
    delay(map(analogRead(4), 603, 1023, keyPressDelayMax, keyPressDelayMin));
  } else if (analogRead(4) < 401) {
    Keyboard.print("h");
    delay(map(analogRead(4), 0, 401, keyPressDelayMin, keyPressDelayMax));
  }

  if (analogRead(5) > 603) {
    Keyboard.print("i");
    delay(map(analogRead(5), 603, 1023, keyPressDelayMax, keyPressDelayMin));
  } else if (analogRead(5) < 401) {
    Keyboard.print("k");
    delay(map(analogRead(5), 0, 401, keyPressDelayMin, keyPressDelayMax));
  }
}
