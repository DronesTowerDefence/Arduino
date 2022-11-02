#include <string.h>
#include "functions/IRSensor.cpp"
#include "functions/Steering.cpp"
#include "functions/AccelerationSensor.cpp"
#include "functions/Light.cpp"
#include "functions/Buzzer.cpp"
#include "functions/BluetoothFunctions.cpp"

void setup()
{
    Serial1.begin(9600);
    Serial.begin(9600);

    pinMode(13, OUTPUT); // StatusLED

    pinMode(lightPin, OUTPUT);       // Licht Vorne/Hinten
    pinMode(indicatorLeftPin, OUTPUT);  // Blinker Links
    pinMode(indicatorRightPin, OUTPUT); // Blinker Rechts
    pinMode(bluetoothStatus, INPUT); // Bluetooth-Status
    pinMode(IRSensorV, INPUT);       // IR-Vorne
    pinMode(IRSensorH, INPUT);       // IR-Hinten
    steeringServo.attach(2);         // PWM-Anschluss des Servo-Motors

    accelerationSensorSetup(); // Setup für den Beschleunigungssensors
}

void loop()
{
    checkBluetoothHeader();
    checkBluetoothConnection();
    checkSteering();
    indicator(3);
    sendBluetoothData(1, accelerationSensorRead());
    sendBluetoothData(2, readIRSensor());

    //delay(50);
}