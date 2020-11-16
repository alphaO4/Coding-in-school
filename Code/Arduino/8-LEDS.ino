int LED1=11;
int LED2=10;
int LED3=9;
int LED4=8;
int LED5=7;
int LED6=6;
int LED7=5;
int LED8=4;
int Eingang=A0;
int Sensorwert=0;
int dwiscool=0;
int helligkeit=0;

void setup(){
pinMode(LED1, OUTPUT)
pinMode(LED2, OUTPUT)
pinMode(LED3, OUTPUT)
pinMode(LED4, OUTPUT)
pinMode(LED5, OUTPUT)
pinMode(LED6, OUTPUT)
pinMode(LED7, OUTPUT)
pinMode(LED8, OUTPUT)
}

void loop(){
dwiscool = 1023/255; 
sensorwert = analogRead(eingang)/dwiscool;
sensorwert = analogRead(eingang);
analogWrite(LED, helligkeit);
helligkeit = sensorwert;





}