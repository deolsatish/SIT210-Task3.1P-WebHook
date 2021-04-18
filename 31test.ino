// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>
#define DHTPIN D6
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);


void setup() {
    Serial.begin(9600); 
    dht.begin();

}

void loop() {
    float t = dht.getTempCelcius();
    String temp=String(t);
    float h = dht.getHumidity();
    String humid=String(h);
    Particle.publish("temp", temp, PRIVATE);
    Particle.publish("humid", humid, PRIVATE);
    delay(30000);

}