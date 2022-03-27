byte pushButton = 2;
byte pinA = 13, pinB = 12, pinC = 11, pinD = 10, pinE = 9, pinF = 8, pinG = 7, pinP = 6;

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
int cRest = -1;
void loop() {
  int buttonState = digitalRead(pushButton);
  Serial.println(buttonState);
  if(buttonState){
    show7Seg(0, 0, 0, 0, 0, 0, 0, 0); 
  }
  else{
    cRest = (cRest+1)%6;
    switch(cRest){
      case 0:
        show7Seg(0, 1, 1, 1, 1, 1, 1, 1);
        delay(300);
        break;
      case 1:
        show7Seg(1, 0, 1, 1, 1, 1, 1, 1);
        delay(300);
        break;
      case 2:
        show7Seg(1, 1, 0, 1, 1, 1, 1, 1);
        delay(300);
        break;
      case 3:
        show7Seg(1, 1, 1, 0, 1, 1, 1, 1);
        delay(300);
        break;
      case 4:
        show7Seg(1, 1, 1, 1, 0, 1, 1, 1);
        delay(300);
        break;
      case 5:
        show7Seg(1, 1, 1, 1, 1, 0, 1, 1);
        delay(300);
        break;
    }
  }
  delay(1); //delay in between reads for stability
}
