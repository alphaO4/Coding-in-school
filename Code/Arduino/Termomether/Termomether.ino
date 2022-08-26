int sensor=A0;
int sensorwert;
int temp = 0;
int t=500;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorwert=analogRead(sensor);
  temp=map(sensorwert, 0,410,-50,150);
  delay(t);
  Serial.print(temp);
  Serial.println(" Celsius");
}
