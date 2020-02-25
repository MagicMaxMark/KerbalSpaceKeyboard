#include <Keyboard.h>

//used by all Muxen
int bits[] = {0,0,0};

//Saved for button Muxen
char mux0Keys[] = {'c', 'm', 'g', 'u', '\b', ' ', 't', 'r'};
char mux1Keys[] = {'0', '1', '2', '3', '4', '5', '6', '7'};
char mux2Keys[] = {'c', 'm', 'g', 'u', '\b', ' ', 't', 'r'};

//Used by button Muxen, Saves get copied here later in the code 
//because I couldn't figure out arrays
char keys[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; //this will change depending on the activated mux

//Saved for button Muxen
bool buttonsPressed0[] = {false, false, false, false, false, false, false, false};
bool buttonsPressed1[] = {false, false, false, false, false, false, false, false};
bool buttonsPressed2[] = {false, false, false, false, false, false, false, false};

//Used by button Muxen, Saves get copied here later in the code 
//because I couldn't figure out arrays
bool buttonsPressed[] = {false, false, false, false, false, false, false, false};

//all pins used in arrays
static const uint8_t readPins[] = {A0, A1, A2, A3, A4};
int writePins0[] = {2, 5, 8, 14};
int writePins1[] = {3, 6, 9, 15};
int writePins2[] = {4, 7, 10, 16};

bool caps_lock_right = false;
bool caps_lock_left  = false;

void setup(){
  //Serial.begin(9600); we only need to uncomment this in debugging
  
  //Mux0 Digital button
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(A0, INPUT);

  //Mux1 Digital button
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(A1, INPUT);

  //Mux2 Digital button
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(A2, INPUT);

  //Mux3 Analog Joystick, Throttle
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(A3, INPUT);

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
  digitalWrite(writePins0[3], bits[0]); //4ths place
  digitalWrite(writePins1[3], bits[1]); //2nds place
  digitalWrite(writePins2[3], bits[2]); //1sts place

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

void muxLoop(int muxNum){
  setMuxKeys(muxNum);
  setButtonsPressed(muxNum, false);
  
  for(int i = 0; i < 8; i ++){
    checkButton(i, muxNum);
  }

  setButtonsPressed(muxNum, true);
}

void setButtonsPressed(int muxNum, bool setSavedButtons){
  if(setSavedButtons){
    if(muxNum == 0){
      for(int i = 0; i < 8; i ++){
        buttonsPressed0[i] = buttonsPressed[i];
      }
    }
    else if(muxNum == 1){
      for(int i = 0; i < 8; i ++){
        buttonsPressed1[i] = buttonsPressed[i];
      }
    }
    else if(muxNum == 2){
      for(int i = 0; i < 8; i ++){
        buttonsPressed2[i] = buttonsPressed[i];
      }
    }
  }
  
  else{
    if(muxNum == 0){
      for(int i = 0; i < 8; i ++){
        buttonsPressed[i] = buttonsPressed0[i];
      }
    }
    else if(muxNum == 1){
      for(int i = 0; i < 8; i ++){
        buttonsPressed[i] = buttonsPressed1[i];
      }
    }
    else if(muxNum == 2){
      for(int i = 0; i < 8; i ++){
        buttonsPressed[i] = buttonsPressed2[i];
      }
    }
  }
}

void checkButton(int button, int muxNum){
  DecimalToBinary(button);
  digitalWrite(writePins0[muxNum], bits[0]);
  digitalWrite(writePins1[muxNum], bits[1]);
  digitalWrite(writePins2[muxNum], bits[2]);

  if(digitalRead(readPins[muxNum]) && !buttonsPressed[button]){
    Keyboard.print(keys[button]);
    buttonsPressed[button] = true;
  }

  else if(!digitalRead(readPins[muxNum]) && buttonsPressed[button]){
    buttonsPressed[button] = false;
  }
}

void setMuxKeys(int muxNum){
  if(muxNum == 0){
    for(int i = 0; i < 8; i++){
      keys[i] = mux0Keys[i];
    }
  }
  
  if(muxNum == 1){
    for(int i = 0; i < 8; i++){
      keys[i] = mux1Keys[i];
    }
  }
  
  if(muxNum == 2){
    for(int i = 0; i < 8; i++){
      keys[i] = mux2Keys[i];
    }
  }
}
