int pushButton = 2; //switch at pin2
int L1 = 13; //LED 1 at pin13
int L2 = 12; //LED 2 at pin12
int L3 = 11; //LED 3 at pin11
int lastButtonState;
int c = 0; //counter

void setup() {
  Serial.begin(9600);

  pinMode(L1, OUTPUT); pinMode(L2, OUTPUT); pinMode(L3, OUTPUT);
  pinMode(pushButton, INPUT);
  c = 0;
}

void loop() {
  int buttonState = digitalRead(pushButton);
  
  Serial.println(c);
  if(buttonState != lastButtonState){ //state changes
    if(buttonState == HIGH){ //from off to on, actually check the state == LOW is working as well
      c = (c+1)%4;
      switch(c){
        case 0:
          //turn all the LEDs off
          digitalWrite(L1, HIGH);
          digitalWrite(L2, HIGH);   
          digitalWrite(L3, HIGH);   
          break;
        case 1:
          digitalWrite(L1, LOW); //turn the 1st LED on
          break;
        case 2:
          digitalWrite(L2, LOW);
          break;
        case 3:
          digitalWrite(L3, LOW);
          break;
      }
    }
    lastButtonState = buttonState; //remember the last state
  }
  delay(1); //delay between reads for stability
}
