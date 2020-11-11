Void Setup {
PinMode(1, INPUT);
PinMode(2, OUTPUT);

VoidLoop { 
Buttonstate = digitalread(1)
LED1 = DigitalWrite(2, HIGH); Delay(200); DigitalWrite(2, LOW) 
LED2 = DigitalWrite(3, HIGH); Delay(200); DigitalWrite(3, LOW) 
LED3 = DigitalWrite(4, HIGH); Delay(200); DigitalWrite(4, LOW) 
LED4 = DigitalWrite(5, HIGH); Delay(200); DigitalWrite(5, LOW)  
LED5 = DigitalWrite(6, HIGH); Delay(200); DigitalWrite(6, LOW) 
LED6 = DigitalWrite(7, HIGH); Delay(200); DigitalWrite(7, LOW) 
LED7 = DigitalWrite(8, HIGH); Delay(200); DigitalWrite(8, LOW)
LED8 = DigitalWrite(9, HIGH); Delay(200); DigitalWrite(9, LOW)  

if (buttonstate==HIGH) { 
    LED1;
    LED2;
    LED3;
    LED4;
    LED8;
    LED7;
    LED6;
    LED5;
}
else {
    LED1;
    LED8;
    LED2;
    LED7;
    LED3;
    LED6;
    LED4;
    LED5;
}