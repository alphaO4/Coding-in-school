int TMP36 = A0; 
int sensorwert;
int temperatur = 0;
int t=500;
int LEDGelb = 3; // Farbe blau an Pin 3
int LEDrot = 5; // Farbe rot an Pin 5
int LEDgruen= 6; // Farbe gruen an Pin 6
int brightness1a = 255; // Zahlenwert zwischen 0 und 255 – gibt die Leuchtstärke der einzelnen Farbe an
int brightness1b = 150; // Zahlenwert zwischen 0 und 255 – gibt die Leuchtstärke der einzelnen Farbe an
int brightness1c = 100; // Zahlenwert zwischen 0 und 255 – gibt die Leuchtstärke der einzelnen Farbe an
int dunkel = 0; // Zahlenwert 0 bedeutet Spannung 0V – also LED aus1

void setup() {
  Serial.begin(9600); 
  pinMode(LEDGelb, OUTPUT);
  pinMode(LEDgruen, OUTPUT);
  pinMode(LEDrot, OUTPUT);

  }

void loop() {
  sensorwert=analogRead(TMP36);
  temperatur= map(sensorwert, 0, 410, -50, 150);
  delay(t);
  Serial.print(temperatur);
  Serial.println(" Grad Celsius");
  if(temperatur >=28)
  {analogWrite(LEDrot, brightness1a);
   analogWrite(LEDGelb, brightness1b);
   analogWrite(LEDgruen, 0);// gruen und rot ein = gelb
  }
  else if(temperatur <28 && temperatur > 24)// gruen und blau ein = türkis
  {analogWrite(LEDGelb, brightness1a);
  analogWrite(LEDrot,brightness1b);
  analogWrite(LEDgruen,brightness1a);}
  
  else if (temperatur <20 && temperatur > 23)
  {analogWrite(LEDgruen, brightness1a);
  analogWrite(LEDrot, 0);
  analogWrite(LEDGelb, brightness1b);// rot und blau ein = lila
  }
}
