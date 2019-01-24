/***************************************************
  This is a library for the HTU21D-F Humidity & Temp Sensor

  Designed specifically to work with the HTU21D-F sensor from Adafruit
  ----> https://www.adafruit.com/products/1899

  These displays use I2C to communicate, 2 pins are required to
  interface
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#ifndef _HTU21_H
#define _HTU21_H

#include "Wire.h"
#include <Arduino.h>

/** Default I2C address for the HTU21D. */
#define HTU21DF_I2CADDR         (0x40)

/** Read temperature register. */
#define HTU21DF_READTEMP        (0xF3)

/** Read humidity register. */
#define HTU21DF_READHUM         (0xF5)

/** Write register command. */
#define HTU21DF_WRITEREG        (0xE6)

/** Read register command. */
#define HTU21DF_READREG         (0xE7)

/** Reset command. */
#define HTU21DF_RESET           (0xFE)

/**
 * Driver for the Adafruit HTU21DF breakout board.
 */
class HTU21 {
    public:
        HTU21();

        boolean begin(int SDA,int SCL);
        float   readTemperature(void);
        float   readHumidity(void);
        void    reset(void);

    private:
        boolean readData(void);
        float _last_humidity, _last_temp;
};

#endif /* _HTU21_H */
