#include "Keyboard.h"
int bits[] = {0,0,0};

bool caps_lock_right = false;
bool caps_lock_left  = false;

void setup(){
  Serial.begin(9600);
  //Serial.print("Hello World");

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(A0, INPUT);

  Keyboard.begin();
}

void loop(){
  muxOneLoop();
}
void muxOneLoop(){
  for(int i = 0; i < 8; i ++){
    checkJoystick(i);
  }
}

void checkJoystick(int axis){
  DecimalToBinary(axis);
  digitalWrite(4, bits[0]); //4ths place
  digitalWrite(3, bits[1]); //2nds place
  digitalWrite(2, bits[2]); //1sts place

  if (axis == 0 && analogRead(A0) > 721){
    Keyboard.press('j');
  } else if (axis == 0 && analogRead(A0) < 319){
    Keyboard.press('l');
  } else if (axis == 0 && 319 < analogRead(A0) && analogRead(A0) < 721){
    Keyboard.release('j');
    Keyboard.release('l');
  }

  if (axis == 1 && analogRead(A0) > 721){
    Keyboard.press('n');
  } else if (axis == 1 && analogRead(A0) < 319){
    Keyboard.press('h');
  } else if (axis == 1 && 319 < analogRead(A0) && analogRead(A0) < 721){
    Keyboard.release('n');
    Keyboard.release('h');
  }

  if (axis == 2 && analogRead(A0) > 721){
    Keyboard.press('i');
  } else if (axis == 2 && analogRead(A0) < 319){
    Keyboard.press('k');
  } else if (axis == 2 && 319 < analogRead(A0) && analogRead(A0) < 721){
    Keyboard.release('i');
    Keyboard.release('k');
  }

  if (axis == 3 && analogRead(A0) > 721){
    //Keyboard.press('s');
    PWM(analogRead(A0), 's', 721, 1010);
  } else if (axis == 3 && analogRead(A0) < 319){
    Keyboard.press('w');
  } else if (axis == 3 && 319 < analogRead(A0) && analogRead(A0) < 721){
    Keyboard.release('s');
    Keyboard.release('w');
  }

  if (axis == 4 && analogRead(A0) > 721){
    Keyboard.press('a');
    PWM(analogRead(A0), 'a', 721, 1000);
  } else if (axis == 4 && analogRead(A0) < 319){
    Keyboard.press('d');
  } else if (axis == 4 && 319 < analogRead(A0) && analogRead(A0) < 721){
    Keyboard.release('a');
    Keyboard.release('d');
  }

  if (axis == 5 && analogRead(A0) > 721){
    //Keyboard.press('q');
    PWM(analogRead(A0), 'q', 721, 1010);
  } else if (axis == 5 && analogRead(A0) < 319){
    Keyboard.press('e');
  } else if (axis == 5 && 319 < analogRead(A0) && analogRead(A0) < 721){
    Keyboard.release('q');
    Keyboard.release('e');
  }

  if ((axis == 6) && digitalRead(A0) == LOW && caps_lock_right == HIGH){
    Keyboard.press(KEY_CAPS_LOCK);
  }
  if ((axis == 6) && digitalRead(A0) == HIGH && caps_lock_right == LOW){
    Keyboard.release(KEY_CAPS_LOCK);
  }
  if (axis == 6){
    caps_lock_right = digitalRead(A0);
  }
  
  if ((axis == 7) && digitalRead(A0) == LOW && caps_lock_left == HIGH){
    Keyboard.press(KEY_CAPS_LOCK);
  }
  if ((axis == 7) && digitalRead(A0) == HIGH && caps_lock_left == LOW){
    Keyboard.release(KEY_CAPS_LOCK);
  }
  if (axis == 7){
    caps_lock_left = digitalRead(A0);
  }
}

void DecimalToBinary(int n) {
   int binaryNumber[] = {0,0,0};
   int i = 0;
   while (n > 0) {
      binaryNumber[2 - i] = n % 2;
      n = n / 2;
      i++;
   }

   bits[0] = binaryNumber[0];
   bits[1] = binaryNumber[1];
   bits[2] = binaryNumber[2];
}

void PWM(int pushedness, char letter, int minimum, int maximum){
  pushedness = map(pushedness, minimum, maximum, 100, 0);
  int antiPushedness = 100-pushedness;
  unsigned long milliseconds = millis();
  while (true){
    milliseconds = milliseconds/10;
    if (milliseconds < 100){
      break;
    }
  }
  if (milliseconds > antiPushedness){
    Keyboard.release(letter);
  } else {
    Keyboard.press(letter);
  }
}
