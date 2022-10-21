#include <string.h>
#include "functions/BluetoothFunctions.cpp"
#include "functions/IRSensor.cpp"
//Gommemode

void setup()
{
    Serial1.begin(9600);
    Serial.begin(9600);

    pinMode(IRSensorV, INPUT);    // IR-Vorne
    pinMode(IRSensorH, INPUT);    // IR-Hinten
    pinMode(IRStatusLED, OUTPUT); // IR-StatusLED
}

void loop()
{
    checkBluetoothHeader();
    sendBluetoothData(2, readIRSensor());

    delay(50);
}