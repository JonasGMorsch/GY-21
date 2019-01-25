#include "Wire.h"
#include <Arduino.h>

/** Default I2C address for the GY-21 */
#define GY21_I2CADDR         (0x40)

/** Read temperature register. */
#define GY21_READTEMP        (0xF3)

/** Read humidity register. */
#define GY21_READHUM         (0xF5)

/** Write register command. */
#define GY21_WRITEREG        (0xE6)

/** Read register command. */
#define GY21_READREG         (0xE7)

/** Reset command. */
#define GY21_RESET           (0xFE)


class GY21 
{
    public:
        GY21();
        boolean begin(int SDA,int SCL);
        float   GY21_Temperature(void);
        float   GY21_Humidity(void);
        void    reset(void);

    private:
        boolean readData(void);
        float _last_humidity, _last_temp;
};
