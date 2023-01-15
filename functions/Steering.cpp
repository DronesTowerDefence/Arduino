// Lenkung
#include <Servo.h>

Servo steeringServo;
const int steeringPosMin = 45;
const int steeringPosMax = 155;
const int steeringPosMid = (steeringPosMax + steeringPosMin) / 2;
int steeringPos = 100;

/// @brief Ändert die Auslenkung der Lenkachse
/// @param changeRotation Grad in welche die Richtung verändert werden soll
/// @return Ob die Auslenkung verändert wurde
bool changeSteering(int changeRotation)
{
    /* Serial.print("ChangeRotation:");
    Serial.println(changeRotation); */

    if (changeRotation == 0)
    {
        steeringPos = steeringPosMid;
        steeringServo.write(steeringPosMid);
        return true;
    }
    else if (steeringPos + changeRotation >= steeringPosMin && steeringPos + changeRotation <= steeringPosMax)
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
    /* Serial.print("Aktuell: ");
    Serial.print(steeringServo.read());
    Serial.print("\tSoll: ");
    Serial.println(steeringPos); */

    steeringServo.write(steeringPos);

    if (steeringPos <= steeringPosMid + 10 && steeringPos >= steeringPosMid - 10)
    {
        indicator(0);
    }
    else if (steeringPos > steeringPosMid + 10)
    {
        indicator(2);
    }
    else if (steeringPos < steeringPosMid - 10)
    {
        indicator(1);
    }
}