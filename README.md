# dr-arduino-i2c-tester
Ardunino: a class to check I2C bus

I transformed the classic function to check the status of the I2C bus into a class. This way when I turn on a hardware I can make sure that the peripherals are connected
# Usage
1. I2CTest i2cTest; Create an instance of the class <br>
2. i2cTest.begin(Wire); inject your Wire object, so you pilot the bus from main class<br>
3. int* addresses = i2cTest.scan(count); execute the scan. 'count' indicates how many devices were found, while 'addresses' is the array of devices addresses<br>
<br>
The main.cpp contain a full example
