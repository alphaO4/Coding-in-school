int LED=9;
int helligkeit=0;
int fadeschritte=5;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(500000);
  }

void loop() {
  analogWrite(LED, helligkeit);
  helligkeit=helligkeit + fadeschritte;
  delay(500);
  Serial.println(helligkeit);
  if(helligkeit==0 || helligkeit== 255)
  {
    Serial.println(helligkeit);
    fadeschritte= -fadeschritte; 
  }
  
  }
