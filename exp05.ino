int sensor = A0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  double out = analogRead(sensor);
  //Serial.println("Temperature: %lf degree celsius", analogRead(A0));
  Serial.print("Temperature: ");
  Serial.print(out/10.*5./1024*1000);
  Serial.println(" degree celsius");

  delay(1000);
}
