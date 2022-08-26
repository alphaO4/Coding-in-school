int 1 = 12;
int 2 = 11;
int 3 = 10;
int 4 = 9;
int 5 = 8;
int 6 = 7;
int 7 = 6;
int 8 = 5;

void setup() {
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  // gruen
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  delay(5000);
  // gelb
  digitalWrite(ampelRotPin, LOW);
  digitalWrite(ampelGelbPin, HIGH);
  digitalWrite(ampelGruenPin, LOW);
  delay(1000);
  // rot
  digitalWrite(ampelRotPin, HIGH);
  digitalWrite(ampelGelbPin, LOW);
  digitalWrite(ampelGruenPin, LOW);
  delay(5000);
  // rot-gelb
  digitalWrite(ampelRotPin, HIGH);
  digitalWrite(ampelGelbPin, HIGH);
  digitalWrite(ampelGruenPin, LOW);
  delay(1000);
}
