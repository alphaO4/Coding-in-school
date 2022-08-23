#include <Servo.h>
Servo myservo;
int pot = 0; 
int value;
void setup() {
    myservo.attach(9);
}
void loop() {
    value = analogRead(pot);
    value = map (value, 0, 1023, 0, 180);
    myservo.write(value);
    delay(15);
}
