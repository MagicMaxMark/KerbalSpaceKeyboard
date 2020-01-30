int bits[] = {0,0,0};

void setup(){
  //Keyboard.begin
  Serial.begin(9600);
  Serial.println("Hello World");

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, INPUT);
}

void loop(){
  if(digitalRead(6) != 0){
    muxOneLoop();
  }

  else{
    Serial.print("Broken :( ");
    Serial.println(digitalRead(6));
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

  if(digitalRead(5)){
    Serial.print(button);
    Serial.println(": true ");
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
