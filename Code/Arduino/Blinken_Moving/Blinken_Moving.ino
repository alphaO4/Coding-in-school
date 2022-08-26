void setup() {
    pinMode(5, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(8, INPUT)
}


void loop() {
  buttonState = digitalRead(8);
    if (buttonState == HIGH) {    
    digitalWrite(4, HIGH);
    delay(1000);
    digitalWrite(4, LOW)
  } else {
    digitalWrite(5, HIGH);
    delay(1000);
    digitalWrite(5, LOW);
    delay(1000);
    digitalWrite(6, HIGH);
    delay(1000);
    digitalWrite(6,LOW);
      
  }
  }
