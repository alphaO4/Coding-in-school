#include <Stepper.h>

// int

int SPU = 2048;
Stepper Motor(SPU, 3, 5, 4, 6);
int red_light_pin = 11;
int green_light_pin = 10;
int blue_light_pin = 9;
int Start = 7;
// int tasterstatus = 0;
int UP = 8;
// int tasterstatus2 = 0;

void setup()
{
  Motor.setSpeed(5);
  pinMode(Start, INPUT);
  pinMode(UP, INPUT);
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
}

void loop()
{
  if (Start == HIGH)
  {
    // Set LED to red
    RGB_color(255,0,0);
    // Wen "Start" gedrückt wird fährt der motor auf punkt 2048
    Motor.step(2048);
  }
  else if (UP == HIGH)
  {
    // Set RGB LED to green
    RGB_color(0,255,0);
    // When "UP" is pressed, go to step -2048
    Motor.step(-2048);
  }
}


void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
{
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}