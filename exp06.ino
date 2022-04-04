int led = 9;

void setup() {
  Serial.begin(9600);
  pinMode(led, INPUT);
}
bool neg = false;
int i = 0;
void loop() {
  if(!neg) i+=1;
  else i-=1;
  if(i==255) neg = true;
  else if(i==0) neg = false;
  analogWrite(led, i);
  delay(10);
}
