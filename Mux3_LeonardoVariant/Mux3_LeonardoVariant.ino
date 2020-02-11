#include <Keyboard.h>

#define muxZeroInput A0
#define muxZeroOutputZero 2
#define muxZeroOutputOne 3
#define muxZeroOutputTwo 4

#define muxOneInput A1
#define muxOneOutputZero 5
#define muxOneOutputOne 6
#define muxOneOutputTwo 7

#define muxTwoInput A2
#define muxTwoOutputZero 8
#define muxTwoOutputOne 9
#define muxTwoOutputTwo 10

#define muxThreeInput A3
#define muxThreeOutputZero 14
#define muxThreeOutputOne 15
#define muxThreeOutputTwo 16

int bits[] = {0,0,0};
char mux0Keys[] = {'1', '2', '3', '4', '5', '6', '7', '8'};
char mux1Keys[] = {'c', 'm', 'g', 'u', KEY_BACKSPACE, ' ', 't', 'r'};
char mux2Keys[] = {'c', 'm', 'g', 'u', KEY_BACKSPACE, ' ', 't', 'r'};

char keys[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; //this will change depending on the activated mux

bool buttonsPressed0[] = {false, false, false, false, false, false, false, false};
bool buttonsPressed1[] = {false, false, false, false, false, false, false, false};
bool buttonsPressed2[] = {false, false, false, false, false, false, false, false};

bool buttonsPressed[] = {false, false, false, false, false, false, false, false};

static const uint8_t readPins[] = {A0,A1,A2,A3,A4};
int writePins0[] = {2, 5, 8, 14};
int writePins1[] = {3, 6, 9, 15};
int writePins2[] = {4, 7, 10, 16};

void setup(){
  Keyboard.begin();
  Serial.begin(9600);
  Serial.println("Hello World");

  //Mux0 Digital button
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(A0, INPUT);

  //Mux1 Digital button
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(A0, INPUT);

  //Mux2 Digital button
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(A2, INPUT);

  //Mux3 Analog Joystick, Throttle
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(A0, INPUT);
}

void loop(){
  if(digitalRead(6) != 0){
    muxLoop(2);
    muxLoop(0);
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
   //
} 
