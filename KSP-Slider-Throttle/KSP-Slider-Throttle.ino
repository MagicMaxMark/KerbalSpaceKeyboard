#include "Keyboard.h"

int pos = 0;

void setup() {
  Serial.begin(9600);
  
  Keyboard.begin();

}

void loop() {
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
    Serial.println("z");
  }
  if (pos == 10){
    Serial.println("x");
  }
}
