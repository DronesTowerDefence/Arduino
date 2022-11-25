// IR-Sensor

const int IRSensorV = 4;
const int IRSensorH = 5;
int IRSensorData = 0;

/// @brief Auslesen der IR-Sensoren
/// @return 0:Nichts | 1:Vorne | 2:Hinten | 3:Beide
int readIRSensor()
{
    IRSensorData = 0;
    
    /* //LED - NUR ZUM TESTEN
    if (digitalRead(IRSensorV) != 1)
    {
        Serial.println("Hindernis");
        digitalWrite(13, HIGH);
    }
    else
    {
        Serial.println("Nichts");
        digitalWrite(13, LOW);
    }
    // */

    if (digitalRead(IRSensorV) != 1)
    {
        IRSensorData += 1;
    }
    if (digitalRead(IRSensorH) != 1)
    {
        IRSensorData += 2;
    }

    return IRSensorData;
}