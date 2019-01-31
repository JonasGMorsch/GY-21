#include <Wire.h>
#include "GY-21.h"

/**
* Constructor for the HTU21DF driver.
 */
 
GY21::GY21()
{
    /* Assign default values to internal tracking variables. */
    _last_humidity = 0.0f;
    _last_temp = 0.0f;
}

/**
 * Initialises the I2C transport, and configures the IC for normal operation.
 *
 * @return true (1) if the device was successfully initialised, otherwise
 *         false (0).
 */
boolean GY21::begin(int SDA,int SCL)
{
    Wire.begin(SDA,SCL);

    reset();

    Wire.beginTransmission(GY21_I2CADDR);
    Wire.write(GY21_READREG);
    Wire.endTransmission();
    Wire.requestFrom(GY21_I2CADDR, 1);
	
    return (Wire.read() == 0x2); // after reset should be 0x2
}

/**
 * Sends a 'reset' request to the HTU21DF, followed by a 15ms delay.
 */
void GY21::reset(void)
{
    Wire.beginTransmission(GY21_I2CADDR);
    Wire.write(GY21_RESET);
    Wire.endTransmission();
    delay(15);
}

/**
 * Performs a single temperature conversion in degrees Celsius.
 *
 * @return a single-precision (32-bit) float value indicating the measured
 *         temperature in degrees Celsius.
 */
float GY21::GY21_Temperature(void)
{
    // OK lets ready!
    Wire.beginTransmission(GY21_I2CADDR);
    Wire.write(GY21_READTEMP);
    Wire.endTransmission();

    //delay(100); // add delay between request and actual read!
	
	while(3 != Wire.requestFrom(GY21_I2CADDR, 3)) // IF THIS GOES, THE CODE GOES DOWN WITH IT
    {
      delay(0); //same as yield for esp
    }


    /* Read 16 bits of data, dropping the last two status bits. */
    uint16_t t = Wire.read();
    t <<= 8;
    t |= Wire.read() & 0b11111100;

    uint8_t crc = Wire.read();
    (void)crc;

    float temp = t;
    temp *= 175.72f;
    temp /= 65536.0f;
    temp -= 46.85f;

    /* Track the value internally in case we need to access it later. */
    _last_temp = temp;

    return temp;
}

/**
 * Performs a single relative humidity conversion.
 *
 * @return A single-precision (32-bit) float value indicating the relative
 *         humidity in percent (0..100.0%).
 */
float GY21::GY21_Humidity(void) 
{
    /* Prepare the I2C request. */
    Wire.beginTransmission(GY21_I2CADDR);
    Wire.write(GY21_READHUM);
    Wire.endTransmission();

    /* Wait a bit for the conversion to complete. */
    //delay(100);

	while(3 != Wire.requestFrom(GY21_I2CADDR, 3)) // IF THIS GOES, THE CODE GOES DOWN WITH IT
    {
      delay(10); //same as yield for esp
    }
	
    /* Read the conversion results. */
    //uint8_t count = Wire.requestFrom(HTU21DF_I2CADDR, 3);

    /* Make sure we got 3 bytes back. */
    //if (count != 3) {
    //    return 0.0f;
    //}

    /* Read 16 bits of data, dropping the last two status bits. */
    uint16_t h = Wire.read();
    h <<= 8;
    h |= Wire.read() & 0b11111100;

    uint8_t crc = Wire.read();
    (void)crc;

    float hum = h;
    hum *= 125.0f;
    hum /= 65536.0f;
    hum -= 6.0f;

    /* Track the value internally in case we need to access it later. */
    _last_humidity = hum;

    return hum;
}
