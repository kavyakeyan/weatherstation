#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 7         // Pin where the DHT11 is connected
#define DHTTYPE DHT11    // Define the type of sensor as DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();                      
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  
  dht.begin(); // Initialize the DHT11 sensor
  delay(2000); // Wait for 2 seconds to ensure sensor starts properly
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperature)) {
    lcd.setCursor(6,0);
    lcd.print("Error");
    lcd.setCursor(10,1);
    lcd.print("Error");
    return;
  }

  lcd.setCursor(6,0);
  lcd.print(temperature);
  lcd.setCursor(9,0);
  lcd.print("C");
  lcd.setCursor(9,1);
  lcd.print("%");
  lcd.setCursor(10,1);
  lcd.print(humidity);
  
  delay(2000); // Wait for 2 seconds before next reading
}
