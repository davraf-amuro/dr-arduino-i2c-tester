#include <Arduino.h>
#include <Wire.h> // Include the I2C stanard library
#include "I2CTest.h" // Include the I2C test class

I2CTest i2cTest; // Create an instance of the I2C test class

void setup() {
    Wire.begin(); // Initialize the I2C bus
    Serial.begin(115200);
    i2cTest.begin(Wire); // Initialize the I2C test class

    Serial.println("\nI2C Scanner");
    Serial.println("\nStart scanning I2C bus...");    
    
    int count; // Number of devices found
    int* addresses = i2cTest.scan(count); // Exec the scan
    
    // check the result
    Serial.println("Scan done.");
    Serial.print("Found ");
    Serial.print(count);
    Serial.println(" I2C devices:");
    for (int i = 0; i < count; i++) {
        Serial.print("Device at address 0x");
        if (addresses[i] < 16) {
            Serial.print("0");
        }
        Serial.println(addresses[i], HEX);
    }
}

void loop() {
    

}