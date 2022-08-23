#include <Servo.h>

Servo myServo;

int sensorValue;
int angle;
const float minTemp = 10; 
const float maxTemp = 30;
const float minSensorValue = 1024.0/5.0*(minTemp/100+0.5);
const float maxSensorValue = 1024.0/5.0*(maxTemp/100+0.5);
const int sensorTemp = A0;

void setup() {
  
  myServo.attach(9); 
  Serial.begin(9600);
}

void loop() {

  sensorValue = analogRead(sensorTemp);
  
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  float voltage = (sensorValue/1024.0)*5.0; 
  float temperature = (voltage - .5)*100;
  Serial.print(", degrees C: ");
  Serial.print(temperature);
  sensorValue = constrain(sensorValue, minSensorValue, maxSensorValue);
  angle = map(sensorValue, maxSensorValue, minSensorValue, 0, 180);
  Serial.print(", angle: ");
  Serial.println(angle);
  myServo.write(angle);
  delay(1000);
}
