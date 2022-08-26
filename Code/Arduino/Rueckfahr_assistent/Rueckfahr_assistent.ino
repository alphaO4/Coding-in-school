int trigger=7;
int echo=6;
long dauer=0;
long entfernung=0;
int Pieper=10;


void setup(){
pinMode(Pieper, OUTPUT);
pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);
}

void loop(){
digitalWrite(trigger, LOW);
delay(3);
digitalWrite(trigger, HIGH); 
delay(3); 
digitalWrite(trigger, LOW); 
dauer = pulseIn(echo, HIGH); 
entfernung = (dauer/2) / 29.1; 
pulseIn(echo, LOW); 
if (entfernung >= 50){
digitalWrite(Pieper, LOW);
delay(1000);
digitalWrite(Pieper, HIGH);
delay(1000);
}
if (entfernung < 50 && entfernung >= 15){
digitalWrite(Pieper, LOW);
delay(500);
digitalWrite(Pieper, HIGH);
delay( 500);
}
if (entfernung < 15){
digitalWrite(Pieper, LOW);
delay(100);
digitalWrite(Pieper, HIGH);
delay(100);}
}
