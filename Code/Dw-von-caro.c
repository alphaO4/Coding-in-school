#include <dhtnew.h>
char t;
#define DHTPIN 2;
#define DHTTYPE DHT11;
#define dht .h(DHTPIN);

void setup()
{
    ​​​​​​​
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
    Serial.begin(9600);
    Serial.println("DHT11 Testprogramm");
    dht.begin();
}

void loop()
{
    delay(2000);
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    if (isnan(h) || isnan(t))
    {
        ​​​​​​​
        Serial.println("Fehler beim auslesen des Sensors!");
        return;

        Serial.print("Luftfeuchtigkeit: ");
        Serial.print(h);
        Serial.print("%\t");
        Serial.print("Temperatur: ");
        Serial.print(t);
        Serial.print("°");
        Serial.println("C");
    }
}
​​​​​​​