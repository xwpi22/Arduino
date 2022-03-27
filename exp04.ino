byte pushButton = 2;
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
  pinMode(pushButton, INPUT);
}
void show7Seg(byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte p){
  digitalWrite(pinA, a); digitalWrite(pinB, b);
  digitalWrite(pinC, c); digitalWrite(pinD, d);
  digitalWrite(pinE, e); digitalWrite(pinF, f);
  digitalWrite(pinG, g); digitalWrite(pinP, p);
  
}
// the loop function runs over and over again forever
int cNo = -1;
int cRest = -1;
void loop() {
  int buttonState = digitalRead(pushButton);
  Serial.println(buttonState);
  if(buttonState){
    cRest = -1;
    cNo = (cNo+1)%9;
    switch(cNo){
      case 0: 
        show7Seg(1, 0, 0, 1, 1, 1, 1, 1); //1 0,B,C,0,0,0,0
        delay(500);
        break;
      case 1:
        show7Seg(0, 0, 0, 0, 0, 0, 1, 1); //0 A,B,C,D,E,F,0
        delay(500);
        break;
      case 2:
        show7Seg(0, 0, 0, 0, 1, 0, 0, 1); //9 A,B,C,D,0,F,G
        delay(500);
        break;
      case 3:
        show7Seg(0, 1, 0, 0, 1, 0, 0, 1); //5 A,0,C,D,0,F,G
        delay(500);
        break;
      case 4:
        show7Seg(1, 0, 0, 1, 1, 1, 1, 1); //1 0,B,C,0,0,0,0
        delay(500);
        break;
      case 5:
        show7Seg(1, 0, 0, 1, 1, 1, 1, 1); //1 0,B,C,0,0,0,0
        delay(500);
        break;
      case 6:
        show7Seg(0, 0, 1, 0, 0, 1, 0, 1); //2 A,B,0,D,E,0,G
        delay(500);
        break;
      case 7:
        show7Seg(0, 0, 0, 0, 1, 0, 0, 1); //9 A,B,C,D,0,F,G
        delay(500);
        break;
      case 8:
        show7Seg(0, 1, 0, 0, 1, 0, 0, 1); //5 A,0,C,D,0,F,G
        delay(500);
        break;
    }
  }
  else{
    cNo = -1;
    cRest = (cRest+1)%6;
    switch(cRest){
      case 0:
        show7Seg(0, 1, 1, 1, 1, 1, 1, 1);
        delay(500);
        break;
      case 1:
        show7Seg(1, 0, 1, 1, 1, 1, 1, 1);
        delay(500);
        break;
      case 2:
        show7Seg(1, 1, 0, 1, 1, 1, 1, 1);
        delay(500);
        break;
      case 3:
        show7Seg(1, 1, 1, 0, 1, 1, 1, 1);
        delay(500);
        break;
      case 4:
        show7Seg(1, 1, 1, 1, 0, 1, 1, 1);
        delay(500);
        break;
      case 5:
        show7Seg(1, 1, 1, 1, 1, 0, 1, 1);
        delay(500);
        break;
    }
  }
  delay(1); //delay in between reads for stability
}
