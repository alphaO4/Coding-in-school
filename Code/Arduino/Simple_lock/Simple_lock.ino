#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
#include <Wire.h> 

MFRC522 mfrc522(SS_PIN, RST_PIN);

int RED = 7;
int GREEN = 6;
int BEEP = A0;
int RELAY_PIN = 4;

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(BEEP, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
}


void loop(){
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  long code=0; 
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    code=((code+mfrc522.uid.uidByte[i])*10);
  }
  Serial.print("Die Kartennummer lautet:");
  Serial.println(code);
  
  if (code == 2688790){
    access_granted(code);
  }
  else if (code == 78452380){
    access_denied(code);
  }
  else if (code == 161680){
    access_granted(code);
  }

  else{
    access_denied(code);
  }
}

int access_granted(long code){
  Serial.print("Karte mit nummer ");
  Serial.print(code);
  Serial.println(" wurde eingelassen");
  digitalWrite(GREEN, HIGH);
  digitalWrite(BEEP, HIGH);
  delay(50);
  digitalWrite(BEEP, LOW);
  delay(50);
  digitalWrite(BEEP, HIGH);
  delay(50);
  digitalWrite(BEEP, LOW);
  digitalWrite(RELAY_PIN, HIGH);
  delay(2000);
  digitalWrite(GREEN, LOW);
  digitalWrite(RELAY_PIN, LOW);
  delay(300);
}

int access_denied(long code){
    Serial.print("Karte mit nummer ");
    Serial.print(code);
    Serial.println(" wurde nicht eingelassen");
    digitalWrite(RED, HIGH);
    digitalWrite(BEEP, HIGH);
    delay(500);
    digitalWrite(BEEP, LOW);
    delay(500);
    digitalWrite(RED, LOW);
    delay(300);
}
