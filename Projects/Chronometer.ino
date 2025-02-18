#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int BtStartStop = 6;
int BtReset = 7;
bool EtatBtStartStop;
bool EtatBtReset;
int EtatBoutonAppuyer;
int EtatChronoOnOFF;
int TempsEcoule;
int Milliseconde;
int Seconde;
int Minute;
int Heure;
unsigned long currentTime = 0;
unsigned long previousTime = 0;


void setup() {
  pinMode(BtStartStop, INPUT_PULLUP);
  pinMode(BtReset, INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.print ("Chrono :");
}

void loop() {
  EtatBtStartStop = digitalRead(BtStartStop);
  EtatBtReset = digitalRead(BtReset);
  if (EtatBtStartStop == LOW && EtatBoutonAppuyer == 0) {
    EtatBoutonAppuyer = 1;
    EtatChronoOnOFF = !EtatChronoOnOFF;
  }
  if (EtatBtReset == LOW && EtatChronoOnOFF == 0 && EtatBoutonAppuyer == 0) {
    EtatBoutonAppuyer = 1;
    Milliseconde = 0;
    //Etc...
    Seconde = 0;
    Minute = 0;
    Heure = 0;
  }
  if (EtatBtStartStop == HIGH && EtatBtReset == HIGH) {
    EtatBoutonAppuyer = 0;
  }
  currentTime = millis();
  TempsEcoule = currentTime - previousTime;
  previousTime = millis();

  // Si EtatChronoOnOFF == 1 on exécute les actions entre {}
  if (EtatChronoOnOFF == 1) {
    // On calcule la valeur de Milliseconde en effectuant une addition entre Milliseconde et TempsEcoule.
    Milliseconde = Milliseconde + TempsEcoule;
    // Si Milliseconde > 999 on exécute les actions entre {}
    if (Milliseconde > 999) {
      Milliseconde = Milliseconde - 1000;
      // On incrémente la variable Seconde de + 1
      Seconde++;
    }
    if (Seconde > 59) {
      Seconde = 0;
      Minute++;
    }
    if (Minute > 59) {
      Minute = 0;
      Heure++;
    }
  }

  lcd.setCursor(9, 1);

  lcd.print(":");
  // Si la variable Milliseconde est plus grande que 99 on exécute les actions entre {}
  if (Milliseconde > 99) {
    lcd.setCursor(10, 1);
    lcd.print(Milliseconde);
  }
  else if (Milliseconde > 9 && Milliseconde < 100) {
    //Etc...
    lcd.setCursor(10, 1);
    lcd.print("0");
    lcd.setCursor(11, 1);
    lcd.print(Milliseconde);
  }
  else if (Milliseconde > 0 && Milliseconde < 10) {
    lcd.setCursor(10, 1);
    lcd.print("00");
    lcd.setCursor(12, 1);
    lcd.print(Milliseconde);
  }
  else {
    lcd.setCursor(9, 1);
    lcd.print(":000");
  }

  lcd.setCursor(6, 1);
  lcd.print(":");
  if (Seconde < 10) {
    lcd.setCursor(7, 1);
    lcd.print("0");
    lcd.setCursor(8, 1);
    lcd.print(Seconde);
  }
  else {
    lcd.setCursor(7, 1);
    lcd.print(Seconde);
  }

  lcd.setCursor(3, 1);
  lcd.print(":");
  if (Minute < 10) {
    lcd.setCursor(4, 1);
    lcd.print("0");
    lcd.setCursor(5, 1);
    lcd.print(Minute);
  }
  else {
    lcd.setCursor(4, 1);
    lcd.print(Minute);
  }
  if (Heure < 10) {
    lcd.setCursor(1, 1);
    lcd.print("0");
    lcd.setCursor(2, 1);
    lcd.print(Heure);
  }
  else {
    lcd.setCursor(1, 1);
    lcd.print(Heure);
  }
}
