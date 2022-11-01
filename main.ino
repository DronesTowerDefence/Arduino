#include <string.h>
#include "functions/BluetoothFunctions.cpp"
#include "functions/IRSensor.cpp"
#include "functions/Steering.cpp"
#include "functions/AccelerationSensor.cpp"

void setup()
{
    Serial1.begin(9600);
    Serial.begin(9600);

    pinMode(IRSensorV, INPUT);    // IR-Vorne
    pinMode(IRSensorH, INPUT);    // IR-Hinten
    pinMode(13, OUTPUT); // IR-StatusLED
    steeringServo.attach(8); //PWM-Anschluss des Servo-Motors

    accelerationSensorSetup();
}

void loop()
{
    checkBluetoothHeader();
    readIRSensor();
    changeServo(90);
    accelerationSensorRead();

    delay(50);
}