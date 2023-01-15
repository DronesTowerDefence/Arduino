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

    pinMode(lightFrontPin1, OUTPUT);    // Licht Vorne
    pinMode(lightFrontPin2, OUTPUT);    // Licht Vorne
    pinMode(lightBackPin, OUTPUT);      // Licht Hinten
    pinMode(indicatorLeftPin, OUTPUT);  // Blinker Links
    pinMode(indicatorRightPin, OUTPUT); // Blinker Rechts
    pinMode(bluelightPin1, OUTPUT);     // Blaulicht
    pinMode(bluelightPin2, OUTPUT);     // Blaulicht
    pinMode(bluetoothStatus, INPUT);    // Bluetooth-Status
    pinMode(pin_IRSensorV, INPUT);      // IR-Vorne
    pinMode(pin_IRSensorH, INPUT);      // IR-Hinten
    steeringServo.attach(2);           // PWM-Anschluss des Servo-Motors
    pinMode(powerrel, OUTPUT);
    pinMode(directrel, OUTPUT);
    accelerationSensorSetup(); // Setup für den Beschleunigungssensors
}

void loop()
{
    // Serial.println(millis());

    delay(20);

    checkBluetoothConnection();
    checkBluetoothHeader();
    checkSteering();
    indicator(-1);
    blueLight(-1);
    horn(2);
    siren(sirenSwitch);
    motorbefehl(-1);

    // Sensor Daten auslesen
    accelerationSensorRead(0);
    readIRSensor();

    // Daten an die App senden
    sendBluetoothData(1, String(acceleration));
    // sendBluetoothData(2, String(IRSensorData));
}