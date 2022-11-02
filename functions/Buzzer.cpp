// Buzzer (Hupe)

const int buzzerPin = 9;
int buzzerCount = 0;

void horn(bool hornSwitch)
{
    if (hornSwitch)
    {
        buzzerCount = 0;
    }
    else
    {
        if (buzzerCount == 0)
        {
            tone(buzzerPin, 500);
        }
        else if (buzzerCount > 50)
        {
            noTone(buzzerPin);
        }
        buzzerCount++;
    }
}