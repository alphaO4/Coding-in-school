int LED=7;
int button1=8;
int tasterstatus1=0;
int ledstat= 0;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(button1, INPUT);
}

  
void loop() {
  tasterstatus1 = digitalRead(button1);
  if (tasterstatus1==HIGH){
    if (ledstat==0) {
      ledstat=1;
      digitalWrite(LED,HIGH);
      }
    else {
      ledstat=0;
      digitalWrite(LED,LOW);
    }
    delay(200);
  }
  }
