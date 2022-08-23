int LED=7;
int button1=8;
int button2=9;
int tasterstatus1=0;
int tasterstatus2=0;
int ledstat= 0;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
}

  
void loop() {
  tasterstatus1 = digitalRead(button1);
  tasterstatus2 = digitalRead(button2);
  if (tasterstatus1==HIGH){
    digitalWrite(LED,LOW);
    delay(200);
  }
  else if (tasterstatus2 == HIGH){
    digitalWrite(LED,HIGH);
    delay(200);
    }
}
