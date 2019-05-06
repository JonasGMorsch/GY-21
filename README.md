# GY-21 Humidity & Temperature Sensor    [![Build Status](https://travis-ci.org/JonasGMorsch/GY-21.svg?branch=master)](https://travis-ci.org/JonasGMorsch/GY-21)


![GY21 Sensor](https://github.com/JonasGMorsch/GY-21/blob/master/documentation/GY-21.jpg)

This is a library for the GY-21 Board (HTU21, SHT21 and Si7021 Sensors).

It runs on ESP8266/ATMega Devices using Arduino IDE.

These boards use **I2C** to communicate.

## Installing this Library

https://www.arduino.cc/en/Guide/Libraries

## How to Use

Go to [Example](https://github.com/JonasGMorsch/GY-21/blob/master/examples/GY-21_test/GY-21_test.ino) or:

1 - ```#include <GY21.h>```

2 - make an object, for example: ```GY21 sensor;```

3 - call ```Wire.begin();``` on setup()

4 - call ```sensor.GY21_Temperature();``` or ```sensor.GY21_Humidity();``` to get the values

**Be Aware:**  It takes ~55ms to get the values


## Sensors Documentation

https://github.com/JonasGMorsch/GY-21/blob/master/documentation/HTU21.pdf

https://github.com/JonasGMorsch/GY-21/blob/master/documentation/SHT21.pdf

https://github.com/JonasGMorsch/GY-21/blob/master/documentation/Si7021.pdf
