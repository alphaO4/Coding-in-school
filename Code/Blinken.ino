Void Setup {
PinMode(1, INPUT);
PinMode(2, OUTPUT);

VoidLoop { 
Buttonstate = digitalread(1)

if (buttonstate==HIGH) {

    DigitalWrite(2, HIGH);
    Delay(1000);
}
else {
    DigitalWrite(2,HIGH);
    Delay(1000)
    DigitalWrite(2, LOW)}
}