#include <Wire.h>
#include <GY-21.h>

#define SCL 14 // D5 ON NODEMCU
#define SDA 12 // D6 ON NODEMCU

// Connect Vin to 3-5VDC
// Connect GND to ground
// Connect SCL to I2C clock pin
// Connect SDA to I2C data pin

GY21 sensor;

void setup()
{
  Serial.begin(250000);
  Serial.println("GY-21_test");

  if (!sensor.begin(SDA, SCL))
  {
    Serial.println("Couldn't find sensor!");
    while (1);
  }
}

void loop()
{
  float temp = sensor.GY21_Temperature();
  float hum = sensor.GY21_Humidity();
  
  Serial.print("Temp: "); 
  Serial.print(temp); 
  Serial.print(" C");
  
  Serial.print("\t\t");
  
  Serial.print("Humidity: "); 
  Serial.print(hum); 
  Serial.println(" \%");
  
  delay(500);
}