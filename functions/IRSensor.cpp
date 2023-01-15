// IR-Sensor

const int pin_IRSensorV = 5;
const int pin_IRSensorH = 4;
int IRSensorData = 0;

/// @brief Auslesen der IR-Sensoren
/// @return 0:Nichts | 1:Vorne | 2:Hinten | 3:Beide
int readIRSensor()
{
    IRSensorData = 0;

    if (digitalRead(pin_IRSensorV) != 1)
    {
        IRSensorData += 1;
    }
    if (digitalRead(pin_IRSensorH) != 1)
    {
        IRSensorData += 2;
    }

    return IRSensorData;
}