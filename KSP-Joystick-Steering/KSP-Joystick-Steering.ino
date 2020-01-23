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
 */

#include "Keyboard.h"

void setup() {
  // open the serial port:
  Serial.begin(9600);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  Serial.println(analogRead(0));
  if (analogRead(0) > 521) {
    Keyboard.print("d");
    delay(map(analogRead(0), 521, 1023, 200, 20));
  } else if (analogRead(0) < 519) {
    Keyboard.print("a");
    delay(map(analogRead(0), 0, 519, 20, 200));
  }
  
  if (analogRead(1) > 503) {
    Keyboard.print("s");
    delay(map(analogRead(1), 503, 1023, 200, 20));
  } else if (analogRead(1) < 501) {
    Keyboard.print("w");
    delay(map(analogRead(1), 0, 501, 20, 200));
  }
}
