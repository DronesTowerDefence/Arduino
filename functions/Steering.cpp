// Lenkung
#include <Servo.h>

Servo steeringServo;
int steeringPos = 100;

/// @brief Ändert die Auslenkung der Lenkachse
/// @param changeRotation Grad in welche die Richtung verändert werden soll
/// @return Ob die Auslenkung verändert wurde
bool changeSteering(int changeRotation)
{
    if(changeRotation == 0)
    {
        // TODO: Auf die Mitte zurücksetzen
    }
    if (steeringPos + changeRotation >= 45 && steeringPos + changeRotation <= 155)
    {
        steeringPos += changeRotation;
        steeringServo.write(steeringPos);
        /* Serial.print("Servo auf: ");
        Serial.println(steeringServo.read()); */
        return true;
    }
    else
        return false;
}

/// @brief Überprüft, ob die Position der Lenkung richtig ist und setzt ggf. den Blinker
void checkSteering()
{
    steeringServo.write(steeringPos);

    if (steeringPos == 100)
    {
        indicator(0);
    }
    else if (steeringPos > 100)
    {
        indicator(2);
    }
    else if (steeringPos < 100)
    {
        indicator(1);
    }
}