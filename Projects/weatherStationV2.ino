#include <DHT.h>;
#include <LiquidCrystal.h>

//Constants
#define DHTPIN 7     // what pin we're connected to
#define DHTTYPE DHT11   // DHT 22  (AM2302)
#define BUZZER_PIN 6
#define redLED 9
#define greenLED 10

DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Variables
float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup()
{
    Serial.begin(9600);
	dht.begin();
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

    // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Weather Station");
  pinMode(BUZZER_PIN, OUTPUT);
    
    // Play a simple melody
    tone(BUZZER_PIN, 500); 
    delay(200);  // Low tone
    tone(BUZZER_PIN, 700); 
    delay(200);  // Medium tone
    tone(BUZZER_PIN, 900); 
    delay(200);  // High tone
    noTone(BUZZER_PIN); 
}

void loop()
{
  //Read data and store it to variables hum and temp
  hum = dht.readHumidity();
  temp= dht.readTemperature();
  //Print temp and humidity values to serial monitor
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %, Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");
  if (temp > 23) {
    digitalWrite(redLED, HIGH);
    tone(BUZZER_PIN, 1000);
    delay(1000);
    noTone(BUZZER_PIN);
    delay(1000);
  } else {
    digitalWrite(greenLED, HIGH);

  }
    // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("Hum: " + String(hum) + " Temp: " + String(temp));
  delay(2000); //Delay 2 sec.
}
