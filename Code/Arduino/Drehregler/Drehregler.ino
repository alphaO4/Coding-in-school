int LED=7;
int eingang=A0;
int Sensorwert=0;
int dwiscool = 1023;;
int geschw=0;

void setup(){
pinMode(LED, OUTPUT);
Serial.begin(9600);
}

void loop(){ 
  Sensorwert = analogRead(eingang) * 2;
  //Serial.println("Sensorwert:");
  Serial.println(Sensorwert);
  digitalWrite(LED, HIGH);
  delay(Sensorwert);
  digitalWrite(LED, LOW);
  delay(Sensorwert);
  //Serial.println("Sensorwert:");
  Serial.println(Sensorwert);
  
}
