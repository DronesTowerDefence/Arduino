#include <string.h>
#include "functions/BluetoothFunctions.cpp"
#include "functions/IRSensor.cpp"

const int statusLED = 13;

void setup()
{
    Serial1.begin(9600);
    Serial.begin(9600);

    pinMode(IRSensorV, INPUT);    // IR-Vorne
    pinMode(IRSensorH, INPUT);    // IR-Hinten
    pinMode(statusLED, OUTPUT); // IR-StatusLED
}

void loop()
{
    checkBluetoothHeader();
    readIRSensor();

    delay(50);
}