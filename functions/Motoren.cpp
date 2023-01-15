
int powerrel = 7, directrel = 8;

void motorbefehl(int signal)
{
    /* Serial.print("Sensor: ");
    Serial.println(IRSensorData);
    Serial.print("Motor: ");
    Serial.println(signal);
    Serial.println(""); */

    if (signal == 0) // Nichts / rollen lassen
    {
        digitalWrite(powerrel, LOW);
        // Serial.println("Nichts");
    }
    else if (signal == 1 && IRSensorData != 1 && IRSensorData != 3) // Vorwärts
    {
        digitalWrite(directrel, HIGH);
        digitalWrite(powerrel, HIGH);
        // Serial.println("Vorwärts");
    }
    else if (signal == 2 && IRSensorData != 2 && IRSensorData != 3) // Bremsen / Rückwärts
    {
        digitalWrite(directrel, LOW);
        digitalWrite(powerrel, HIGH);
        // Serial.println("Rückwärts");
    }
}