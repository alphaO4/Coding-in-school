int eingang=A0;
int LED=13;
int sensorwert=0;

void setup()
{ pinMode (LED, OUTPUT);
}

void loop()
{ sensorwert=(analogRead(eingang)/14);
 if {(sensorwert = 0)
  digitalWrite (LED, HIGH);}
  else {digitalWrite (LED, LOW);}
  