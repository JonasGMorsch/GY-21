#include <GY21.h>

#ifdef ESP8266
#define SCL 14 // D5 ON NODEMCU
#define SDA 12 // D6 ON NODEMCU
#endif

// Connect VIN to 3-5VDC
// Connect GND to ground
// Connect SCL to I2C clock pin
// Connect SDA to I2C data pin

GY21 sensor;

void setup()
{
  Serial.begin(74880);
  Serial.println("GY-21_test");

#ifdef ESP8266
  Wire.begin(SDA, SCL);
#else
  Wire.begin();
#endif

}

void loop()
{
  float temp = sensor.GY21_Temperature();
  float hum = sensor.GY21_Humidity();

  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print("°C    ");
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.println("\%");

  delay(500);
}
