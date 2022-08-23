#include <Stepper.h>

const int stepsPerRevolution = 200; 

Stepper myStepper(stepsPerRevolution, 3, 4, 5, 6);

int stepCount = 0;
void setup() {
}

void loop() {
  int sensorReading = analogRead(A0);
  int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
    myStepper.step(stepsPerRevolution / 100);
  }
}
