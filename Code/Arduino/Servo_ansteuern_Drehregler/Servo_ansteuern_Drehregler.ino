#include <Servo.h>
Servo servo;
int regler=A0;
int sensorwert = 0;
void setup() {
  // put your setup code here, to run once:
  servo.attach(9);
  Serial.begin(4800);
}

void loop() { 
  sensorwert = analogRead(regler);
  sensorwert = sensorwert/5,68333;
  Serial.println(sensorwert);
  servo.write(sensorwert);
  delay(10);
}
