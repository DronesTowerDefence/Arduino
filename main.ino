#include <string.h>
#include "functions/IRSensor.cpp"
#include "functions/AccelerationSensor.cpp"
#include "functions/Light.cpp"
#include "functions/Buzzer.cpp"
#include "functions/Steering.cpp"
#include "functions/Motoren.cpp"
#include "functions/BluetoothFunctions.cpp"

// Arduino darf nicht länger als 49.17 Tage am Stück laufen wegen Daten-Überlauf
// Der Arduino braucht ca. 35 Millisekunden, um einmal die loop-Funktion zu durchlaufen.

void setup()
{
    Serial1.begin(9600);
    Serial.begin(9600);

    pinMode(13, OUTPUT);                // StatusLED
    pinMode(lightPin, OUTPUT);          // Licht Vorne/Hinten
    pinMode(indicatorLeftPin, OUTPUT);  // Blinker Links
    pinMode(indicatorRightPin, OUTPUT); // Blinker Rechts
    pinMode(bluetoothStatus, INPUT);    // Bluetooth-Status
    pinMode(IRSensorV, INPUT);          // IR-Vorne
    pinMode(IRSensorH, INPUT);          // IR-Hinten
    steeringServo.attach(2);            // PWM-Anschluss des Servo-Motors
    pinMode(powerrel, OUTPUT);
    pinMode(directrel, OUTPUT);
    pinMode(safetyrel, OUTPUT);
    accelerationSensorSetup(); // Setup für den Beschleunigungssensors
}

void loop()
{
    checkBluetoothConnection();
    checkBluetoothHeader();
    checkSteering();
    indicator(3);
    horn(2);
    motorbefehl(-1);

    // Sensor Daten auslesen
    accelerationSensorRead(0);
    readIRSensor();

    // Daten an die App senden
    sendBluetoothData(1, String(acceleration));
    // sendBluetoothData(2, String(IRSensorData));
}
