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
char mux1Keys[] = {'c', 'm', 'g', 'u', KEY_BACKSPACE, ' ', 't', 'r'};
char keys[] = {'c', 'm', 'g', 'u', KEY_BACKSPACE, ' ', 't', 'r'};
bool buttonsPressed[] = {false, false, false, false, false, false, false, false};

void setup(){
  Keyboard.begin();
  Serial.begin(9600);
  Serial.println("Hello World");

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(A0, INPUT);
}

void loop(){
  if(digitalRead(6) != 0){
    muxOneLoop();
  }
}

void muxOneLoop(){
  for(int i = 0; i < 8; i ++){
    checkButton(i);
  }
}

void checkButton(int button){
  DecimalToBinary(button);
  digitalWrite(2, bits[0]);
  digitalWrite(3, bits[1]);
  digitalWrite(4, bits[2]);

  if(digitalRead(A0) && !buttonsPressed[button]){
    Keyboard.print(keys[button]);
    buttonsPressed[button] = true;
  }

  else if(buttonsPressed[button] && !digitalRead(A0)){
    buttonsPressed[button] = false;
  }
}

void setMuxKeys(int muxNum){
  for(int i = 0; i < 8; i++){
    keys[i] = mux1Keys[i];
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
