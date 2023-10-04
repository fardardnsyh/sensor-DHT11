
#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>
#include <DHT.h>
#define DHTPIN 3
#define DHTTYPE DHT11
LiquidCrystal_I2C lcd(0x27,16,2);  
DHT dht(DHTPIN,DHTTYPE);
void setup() 
{
  Serial.begin(9600);
  dht.begin();
  lcd.init();   
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("info tenik");
 
  lcd.setCursor(0,1);
  lcd.print("youtube");
  delay(1000);
}

void loop() 
{
 float h = dht.readHumidity();
 float t = dht.readTemperature();

lcd.setCursor(0,0);
lcd.print("Suhu "); 
lcd.print(t);
lcd.setCursor(0,1);
lcd.print("Kelembaban ");
lcd.print(h);
delay(1000);

}
