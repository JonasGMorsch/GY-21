#ifndef GY21_H
#define GY21_H

#include <Arduino.h>
#include <Wire.h>

//Default I2C address for the GY-21
#define GY21_I2CADDR    0x40

//Read temperature register
#define GY21_READTEMP   0xF3

//Read humidity register
#define GY21_READHUM    0xF5

//Read register command
#define GY21_READREG    0xE7

//Reset command
#define GY21_RESET      0xFE

template <typename WireType>
class GY21_
{
  public:

    void GY21() {}

    unsigned char setup(WireType &t = Wire)
    {
      wire = &t;

      reset();

      wire->beginTransmission(GY21_I2CADDR);
      wire->write(GY21_READREG);
      wire->endTransmission();
      wire->requestFrom(GY21_I2CADDR, 1);

      return (wire->read() == 0x2); // after reset should be 0x2
    }
    
    void reset(void)
    {
      wire->beginTransmission(GY21_I2CADDR);
      wire->write(GY21_RESET);
      wire->endTransmission();
      delay(15);
    }

    float GY21_Temperature(void)
    {
      wire->beginTransmission(GY21_I2CADDR);
      wire->write(GY21_READTEMP);
      wire->endTransmission();

      while (3 != wire->requestFrom(GY21_I2CADDR, 3)) // IF THIS GOES, THE CODE GOES DOWN WITH IT
      {
        delay(0); //same as yield for esp
      }

      return ((((wire->read() << 8) | (wire->read() & 0b11111100)) * 175.72f / 65536.0f) - 46.85f);
    }

    float GY21_Humidity(void)
    {
      wire->beginTransmission(GY21_I2CADDR);
      wire->write(GY21_READHUM);
      wire->endTransmission();

      while (3 != wire->requestFrom(GY21_I2CADDR, 3)) // IF THIS GOES, THE CODE GOES DOWN WITH IT
      {
        delay(0); //same as yield for esp
      }

      return ((((wire->read() << 8) | (wire->read() & 0b11111100)) * 125.0f / 65536.0f) - 6.0f);
    }

  private:
    boolean readData(void);
    WireType* wire;
};

using GY21 = GY21_<TwoWire>;
#endif GY21_H