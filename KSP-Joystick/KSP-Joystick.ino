/*  Controller for Kerbal Space Program.
 *  Use the joystick for WASD(QE)
 *  
 *  PIN-OUT
 *  –––––––––––––––––––-––––
 *  ddddd
 *        |Y ––––––– A0|
 *  joy   |X ––––––– A1|
 *        |Bt –––––– NC| arduino
 *  stick |VCC ––––– 5v|
 *        |GND –––– GND|
 *  
 *  
 * 
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
  if (analogRead(0) > 520) {
    Keyboard.print("a");
    delay(map(analogRead(0), 520, 1023, 200, 20));
  } else if (analogRead(0) < 520) {
    Keyboard.print("d");
    delay(map(analogRead(0), 0, 520, 20, 200));
  }
  
  if (analogRead(1) > 502) {
    Keyboard.print("s");
    delay(map(analogRead(1), 502, 1023, 200, 20));
  } else if (analogRead(1) < 502) {
    Keyboard.print("w");
    delay(map(analogRead(1), 0, 502, 20, 200));
  }
}
