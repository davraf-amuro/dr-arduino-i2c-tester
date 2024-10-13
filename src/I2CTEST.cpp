#include "I2CTest.h"

void I2CTest::begin(TwoWire &wire) {
    this->wire = &wire;
}

int* I2CTest::scan(int &count) {
    return scan(count, false);
}

int* I2CTest::scan(int &count, bool verbose) {
    static int foundAddresses[128]; // Array statico per memorizzare gli indirizzi trovati, +1 per il terminatore
    count = 0; // Numero di dispositivi trovati
    byte error, address;
    Serial.println("Scanning...");
    for(address = 1; address < 127; address++ ) {
        wire->beginTransmission(address);
        error = wire->endTransmission();
        if (error == 0) {
            foundAddresses[count] = address;
            count++;
            if (verbose) {
                Serial.print("I2C device found at address 0x");
                if (address < 16) {
                    Serial.print("0");
                }
                Serial.println(address, HEX);
            }
        }
        else if (error == 4) {
            if (verbose) {
                Serial.print("Unknown error at address 0x");
                if (address < 16) {
                    Serial.print("0");
                }
                Serial.println(address, HEX);
            }
        }
    }
    foundAddresses[count] = -1; // Aggiungi il terminatore
    if (count == 0) {
        if (verbose) {
            Serial.println("No I2C devices found\n");
        }
    }
    else {
        if (verbose) {
            Serial.println("done\n");
        }
    }
    return foundAddresses;
}

