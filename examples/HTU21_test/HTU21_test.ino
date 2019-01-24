#include <Wire.h>
#include <HTU21.h>

#define SCL 14
#define SDA 12

// Connect Vin to 3-5VDC
// Connect GND to ground
// Connect SCL to I2C clock pin
// Connect SDA to I2C data pin

HTU21 sensor;

void setup()
{
  Serial.begin(250000);
  Serial.println("HTU21 test");

  if (!sensor.begin(SDA, SCL))
  {
    Serial.println("Couldn't find sensor!");
    while (1);
  }
}

void loop()
{
  float temp = sensor.readTemperature();
  float rel_humidity = sensor.readHumidity();
  
  Serial.print("Temp: "); 
  Serial.print(temp); 
  Serial.print(" C");
  
  Serial.print("\t\t");
  
  Serial.print("Humidity: "); 
  Serial.print(rel_humidity); 
  Serial.println(" \%");
  
  delay(500);
}