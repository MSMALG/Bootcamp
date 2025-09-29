int voltReaderPin = A3;
int readVal;
float V2;
int dt = 250;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(voltReaderPin);
  V2 = (5.0 /1023.0) * readVal; 
  Serial.println(V2);
  delay(dt);
}
