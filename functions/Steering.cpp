#include <Servo.h>

Servo steeringServo;

bool changeServo(int changeRotation)
{
    if (changeRotation >= 45 && changeRotation <= 155)
    {
        steeringServo.write(changeRotation);
        Serial.print("Servo auf: ");
        Serial.println(steeringServo.read());
        return true;
    }
    else return false;

}