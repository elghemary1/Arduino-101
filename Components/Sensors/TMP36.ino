const int sensePin = A0;
int sensorInput; 
float temp; 

void setup() {
Serial.begin(9600);

}

void loop() {
sensorInput = analogRead(A0);
temp = (double)sensorInput / 1024;
temp = temp * 5;
temp = temp – 0.5;
temp = temp * 100;

Serial.print("Temperature: ");
Serial.println(temp);
}
