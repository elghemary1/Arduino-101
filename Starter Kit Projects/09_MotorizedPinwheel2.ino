const int motorPin = 9;
int const potPin = A0;
int potVal;

void setup(){
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  potVal = analogRead(potPin);
  analogWrite(motorPin, potVal);
  Serial.println(potVal);
  delay(500);
}
