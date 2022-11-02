// Lenkung
#include <Servo.h>

Servo steeringServo;

bool changeServo(int changeRotation)
{
    int tmp = steeringServo.read();
    if (tmp + changeRotation >= 45 && tmp + changeRotation <= 155)
    {
        steeringServo.write(tmp + changeRotation);
        Serial.print("Servo auf: ");
        Serial.println(steeringServo.read());
        return true;
    }
    else
        return false;
}