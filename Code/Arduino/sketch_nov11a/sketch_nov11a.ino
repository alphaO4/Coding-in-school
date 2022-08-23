int eingang=A0;
int LED=9;
int sensorwert=0;

void setup()
{ pinMode (LED, OUTPUT);
}

void loop()
{ sensorwert=(analogRead(eingang)/14);
 if (sensorwert = 1)
  {digitalWrite (LED, HIGH);}
  else (sensorwert < 1);
  {digitalWrite (LED, LOW);}
}
