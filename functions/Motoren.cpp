
int powerrel = 10, directrel = 11, safetyrel = 12;

void motorbefehl(int signal)
{
    /* Serial.print("Sensor: ");
    Serial.println(IRSensorData);
    Serial.print("Motor: ");
    Serial.println(signal);
    Serial.println(""); */
    if (IRSensorData == 0)
    {
        if (signal == 0) // Nichts / rollen lassen
        {
            digitalWrite(powerrel, LOW);
            //Serial.println("Nichts");
        }
        else if (signal == 1) // Vorwärts
        {
            digitalWrite(directrel, HIGH);
            digitalWrite(powerrel, HIGH);
            digitalWrite(safetyrel, HIGH);
            //Serial.println("Vorwärts");
        }
        else if (signal == 2) // Bremsen / Rückwärts
        {
            digitalWrite(directrel, LOW);
            digitalWrite(powerrel, HIGH);
            digitalWrite(safetyrel, LOW);
            //Serial.println("Rückwärts");
        }
    }
    else
    {
        digitalWrite(directrel, LOW);
        digitalWrite(powerrel, LOW);
        digitalWrite(safetyrel, LOW);
    }
}