#include <Stepper.h>
int SPU = 2048;
Stepper Motor(SPU, 3,5,4,6);
int Taster1=10; 
int Taster2=11;
int Tasterstatus1; 
int Tasterstatus2;
void setup()
{
Motor.setSpeed(15);
pinMode(Taster1, INPUT);
pinMode(Taster2, INPUT);
}
void loop() 
{
Tasterstatus1=digitalRead(Taster1); 
if (Tasterstatus1 == HIGH)
 {
 Motor.step(-1);
 Tasterstatus1=digitalRead(Taster1);
 } 
 else {
   if (Tasterstatus2 == HIGH)
 {
 Motor.step(1);
 Tasterstatus2=digitalRead(Taster2);
 } 
 
 }
}
