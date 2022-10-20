// IR-Sensor-Zeug

const int IRSensorV = 2;
const int IRSensorH = 4;
const int IRStatusLED = 13;

/// @brief Auslesen der IR-Sensoren
/// @return 0:Nichts | 1:Vorne | 2:Hinten | 3:Beide
int readIRSensor()
{
    int returnValue = 0;

    /* //LED - NUR ZUM TESTEN
    if (digitalRead(IRSensorV) == 1)
    {
        Serial.println("An");
        digitalWrite(IRStatusLED, HIGH);
    }
    else
    {
        Serial.println("Aus");
        digitalWrite(IRStatusLED, LOW);
    }
    // */

    if (digitalRead(IRSensorV) == 1)
    {
        returnValue += 1;
    }
    if (digitalRead(IRSensorH) == 1)
    {
        returnValue += 2;
    }

    return returnValue;
}