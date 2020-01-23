int inputPinRead = 0;
int lowsA0[] = {257,355,559,591,628,671,720,776,843,920};
int highsA0[] = {277,375,579,611,648,691,740,796,863,940};
char lettersA0[] = {'a','b','c','d','e','f','g','h','i','j'};
bool triggrdA0[] = {false, false, false, false, false, false, false, false, false, false}

void setup() {
  Serial.begin(9600);
  Serial.println("hello");
}

void loop() {
  if(analogRead(A1) == LOW){ //this the code won't run uunless we have a button pluged into A1 and are not using it
    keyboard();
  }

  else if(analogRead(A1) != LOW && analogRead(A1) != HIGH){
    Serial.print(A1);
    Serial.println(" missing stop button");
  }
  
  else{
    //delay(60000);//delays 1 minate
    Serial.print("A1 ");
    Serial.println(analogRead(A1));
  }

}

void keyboard(){//this is where we will put the code that makes the keyboard work
  inputPinRead = analogRead(A0);
  getInputA0();
}

//Funtions
void getInputA0(){//this is my name for the multipul buttons in one 
  for(int checks = 0; checks < 10; checks += 1){
    if(checkRange(inputPinRead, lowsA0[checks], highsA0[checks])){
      Serial.println(lettersA0[checks]);
      return;
    }
  }
}

bool checkRange(int n, int low, int high){
  if(n > low && n < high){
    return true;
  }
  
  else{
    return false;
  }
}
