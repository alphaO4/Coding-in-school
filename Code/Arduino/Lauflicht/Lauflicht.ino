int licht_1 = 12;
int licht_2 = 11;
int licht_3 = 10;
int licht_4 = 9;
int licht_5 = 8;
int licht_6 = 7;
int licht_7 = 5;
int licht_8 = 4;

void setup() {
  pinMode(licht_1, OUTPUT);
  pinMode(licht_2, OUTPUT);
  pinMode(licht_3, OUTPUT);
  pinMode(licht_4, OUTPUT);
  pinMode(licht_5, OUTPUT);
  pinMode(licht_6, OUTPUT);
  pinMode(licht_7, OUTPUT);
  pinMode(licht_8, OUTPUT);
}

void loop() {
  delay(50);
  digitalWrite(licht_2, HIGH);
  digitalWrite(licht_1, LOW);
  delay(50);
  digitalWrite(licht_3, HIGH);
  digitalWrite(licht_2, LOW);
  delay(50);
  digitalWrite(licht_4, HIGH);
  digitalWrite(licht_3, LOW);
  delay(50);
  digitalWrite(licht_5, HIGH);
  digitalWrite(licht_4, LOW);
  delay(50);
  digitalWrite(licht_6, HIGH);
  digitalWrite(licht_5, LOW);
  delay(50);
  digitalWrite(licht_7, HIGH);
  digitalWrite(licht_6, LOW);
  delay(50);
  digitalWrite(licht_8, HIGH);
  digitalWrite(licht_7, LOW);
  delay(50);
  digitalWrite(licht_8, LOW);
  digitalWrite(licht_7, HIGH);
  delay(50);
  digitalWrite(licht_6, HIGH);
  digitalWrite(licht_7, LOW);
  delay(50);
  digitalWrite(licht_5, HIGH);
  digitalWrite(licht_6, LOW);
  delay(50);
  digitalWrite(licht_5, HIGH);
  digitalWrite(licht_4, LOW);
  delay(50);
  digitalWrite(licht_4, HIGH);
  digitalWrite(licht_5, LOW);
  delay(50);
  digitalWrite(licht_3, HIGH);
  digitalWrite(licht_4, LOW);
  delay(50);
  digitalWrite(licht_2, HIGH);
  digitalWrite(licht_3, LOW);
  delay(50);
  digitalWrite(licht_1, HIGH);
  digitalWrite(licht_2, LOW); 
}
