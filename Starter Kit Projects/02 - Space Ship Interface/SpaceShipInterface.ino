int switchState = 0;
int redLed1 = 5;
int redLed2 = 4;
int greenLed = 3;

void setup() {
  Serial.begin(9600);
  pinMode(switchState, INPUT);
  pinMode(redLed1, OUTPUT);
  pinMode(redLed2, OUTPUT);
  pinMode(greenLed, OUTPUT);

}

void loop() {
  switchState = digitalRead(2);
  if (switchState == LOW){
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed2, LOW);
    digitalWrite(redLed1, LOW);
  }

  else {
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed2, LOW);
    digitalWrite(redLed1, HIGH);
    delay(250);

    digitalWrite(redLed2, HIGH);
    digitalWrite(redLed1, LOW);
    delay(250);
  }
  
}
