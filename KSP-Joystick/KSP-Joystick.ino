/*  Controller for Kerbal Space Program.
 *  Use the joystick for WASD(QE)
 *  
 *  PIN-OUT
 *  –––––––––––––––––––-––––
 *  
 *        |Y ––––––– A0|
 *  joy   |X ––––––– A1|
 *        |Bt –––––– NC| arduino
 *  stick |VCC ––––– 5v|
 *        |GND –––– GND|
 */
#include "Keyboard.h"

const byte ROWS = 1;
const byte COLS = 10;

bool oldstate4 = false;
bool newstate4 = false;
void setup() {
  // open the serial port:
  Serial.begin(9600);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  
  if (analogRead(0) >= 1000) {
    Keyboard.print("d");
  } else if (analogRead(0) <= 23) {
    Keyboard.print("a");
  }
  
  if (analogRead(1) >= 1000) {
    Keyboard.print("s");
  } else if (analogRead(1) <= 23) {
    Keyboard.print("w");
  }

  delay(100);
}
