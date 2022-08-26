int LED=9;
int eingang=A0;
int helligkeit=0;
int Sensorwert=0;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  }

void loop() {
  Sensorwert = analogRead(eingang)/4;
  //Serial.println("Sensorwert:");
  Serial.println(Sensorwert);
  helligkeit=Sensorwert;
  analogWrite(LED, helligkeit);
  }
