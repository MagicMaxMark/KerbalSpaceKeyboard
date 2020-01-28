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
 *  
 * 
 */

#include "Keyboard.h"

void setup() {
  // open the serial port:
  Serial.begin(9600);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
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
}
