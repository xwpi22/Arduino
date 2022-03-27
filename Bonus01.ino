byte pushButton = 2;
bool up = 1;
byte pinA = 13, pinB = 12, pinC = 11, pinD = 10, pinE = 9, pinF = 8, pinG = 7, pinP = 6;
byte n0[8] = {0, 0, 0, 0, 0, 0, 1, 1};
byte n1[8] = {1, 0, 0, 1, 1, 1, 1, 1};
byte n2[8] = {0, 0, 1, 0, 0, 1, 0, 1};
byte n3[8] = {0, 0, 0, 0, 1, 1, 0, 1};
byte n4[8] = {1, 0, 0, 1, 1, 0, 0, 1};
byte n5[8] = {0, 1, 0, 0, 1, 0, 0, 1};
byte n6[8] = {0, 0, 0, 0, 0, 1, 0, 1};
byte n7[8] = {0, 0, 0, 1, 1, 1, 1, 1};
byte n8[8] = {0, 0, 0, 0, 0, 0, 0, 1};
byte n9[8] = {0, 0, 0, 0, 1, 0, 0, 1};

void setup() {
  Serial.begin(9600);
  
  pinMode(pinA, OUTPUT); pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT); pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT); pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT); pinMode(pinP, OUTPUT);
  
  // initialize digital pin LED_BUILTIN as an output.
  attachInterrupt(digitalPinToInterrupt(pushButton), inverse, FALLING);
}
void show7Seg(byte num[8]){
  digitalWrite(pinA, num[0]); digitalWrite(pinB, num[1]);
  digitalWrite(pinC, num[2]); digitalWrite(pinD, num[3]);
  digitalWrite(pinE, num[4]); digitalWrite(pinF, num[5]);
  digitalWrite(pinG, num[6]); digitalWrite(pinP, num[7]);
  
}
void inverse(){
  up = !up;
}
// the loop function runs over and over again forever
int cNo = -1;
int cRest = -1;
int cur = -1;
void loop() {
  if(up){
    cur = (cur+1)%10;
  }
  else{
    cur-=1;
    if(cur == -1){
      cur = 9;
    }
  }
  //Serial.println(cur);
  Serial.println(up);
  switch(cur){
    
    case 0: 
      show7Seg(n0);
      delay(500);
      break;
    case 1:
      show7Seg(n1);
      delay(500);
      break;
    case 2:
      show7Seg(n2); 
      delay(500);
      break;
    case 3:
      show7Seg(n3); 
      delay(500);
      break;
    case 4:
      show7Seg(n4); 
      delay(500);
      break;
    case 5:
      show7Seg(n5); 
      delay(500);
      break;
    case 6:
      show7Seg(n6); 
      delay(500);
      break;
    case 7:
      show7Seg(n7); 
      delay(500);
      break;
    case 8:
      show7Seg(n8);
      delay(500);
      break;
    case 9:
      show7Seg(n9);
      delay(500);
      break;
  }
  //delay(1); //delay in between reads for stability
}
