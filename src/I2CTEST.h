#ifndef I2CTEST_H
#define I2CTEST_H

#include <Arduino.h>
#include <Wire.h>

class I2CTest {
public:
    void begin(TwoWire &wire);
    int* scan(int &count);

private:
    TwoWire* wire;
    int* scan(int &count, bool verbose);
};

#endif // I2CTEST_H