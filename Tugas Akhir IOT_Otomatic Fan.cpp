#define BLYNK_TEMPLATE_ID "TMPL9BNmgZQ3"
#define BLYNK_DEVICE_NAME "IRFAN"
#define BLYNK_AUTH_TOKEN "Z1-uYadVw-MaSCukoidJn5-Ws_OFTK6w"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>  
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char ssid[] = "INNOVATE BELAKANG";  
char pass[] = "puring11belakang";  
char auth[] = BLYNK_AUTH_TOKEN;

#define DHTPIN 4 //d2
#define DHTTYPE DHT11
#define RELAY 5 //d1
#define LED 0 //d3
WidgetLED FAN(V0);

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void dhtstart ()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
    Blynk.virtualWrite(V2, h);
    Blynk.virtualWrite(V1, t);
if (t < 29)//dingin
{
    delay(100);
    digitalWrite(RELAY, HIGH); 
    FAN.off();
  }
  else if (t >= 29)//panas
  { 
    delay(100);
    digitalWrite(RELAY, LOW); 
    FAN.on();
    digitalWrite(LED, HIGH); 
    delay(100);
    digitalWrite(LED, LOW); 
    delay(2000);
  }
   else //normal
{
    digitalWrite(RELAY, HIGH); 
    FAN.off();
    digitalWrite(LED, HIGH); 
}
}



void loop() {
  Blynk.run(); 
  timer.run();
}