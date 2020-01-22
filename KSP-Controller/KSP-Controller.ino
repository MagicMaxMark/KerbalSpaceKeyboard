/*  Controller for Kerbal Space Program.
 *  Use the joystick for WASD
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
 *  ENCLOSURE
 *  –––––––––––––––––––-––––
 *  _______________________
 *  |                     |
 *  |   (☐)    ()         |
 *  |        O    ☐   O   |
 *  |  O o O O    O O o O |
 *  |____^____________^___|
 *      LED          LED
 *   Joystick|----Shift
 *  _____|___|_____________
 *  |    V   |    t       |
 *  |   (☐)  V () V       |
 *  |        O  ^ ☐   O   |
 *  |  O   O O  | O O ^ O |
 *  |__^___^_^__|_^_^_|_^_|
 *     z   x |Spce| | | |
 *          CTR   m , / .
 */
#include "Keyboard.h"
#include <Keypad.h>

const byte ROWS = 1;
const byte COLS = 10;
char keys[ROWS][COLS] = {
{'z','x',0x80,0x81,' ','t','m',',','/','.'},
};
byte rowPins[ROWS] = {33};
byte colPins[COLS] = {2,3,4,5,6,7,8,9,10,11};

bool oldstate4 = false;
bool newstate4 = false;
void setup() {
  // open the serial port:
  Serial.begin(9600);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  ledColor(analogRead(1), 1023, 0);
  ledColor(analogRead(0), 1023, 4);
  
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

void ledColor(int num, int maximum, int nth){
  int red = map(num, 0, maximum, 0, 255);
  int green = map(num, 0, maximum, 255, 0);
  analogWrite(nth + 5, red);
  analogWrite(nth + 6, green);
  
}
